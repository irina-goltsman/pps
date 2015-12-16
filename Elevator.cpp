#include <Elevator.h>

void ConcreteStupidRanker::Rank(int current_floor,
                           QVector<int> *ranked_floors, int new_floor)
{
    ranked_floors->append(new_floor);
}

QElevator::QElevator(RankerInterface *ranker_): ranker(ranker_)
{
    lighting_status = false;
    timer = new QTimer(this);
    current_floor = 1;
    is_blocked = false;
    is_moving = false;
}

QElevator::~QElevator()
{
    destroyConnections();
    timer->stop();
    delete timer;
    delete ranker;
}

void QElevator::HandleSmokeEvent(bool is_smoked)
{
    if (this->is_blocked && !is_smoked) {
        is_blocked = is_smoked;
        // Значит задымление устранено, можно продолжить ехать дальше
        moveTo();
    } else {
        is_blocked = is_smoked;
    }

}

void QElevator::HandleWeightEvent(bool is_overloaded)
{
}

void QElevator::HandleAddFloorTask(int floor)
{
    if (is_on) {
        ranker->Rank(current_floor, &ranked_floors, floor);
        emit TaskListChanged(ranked_floors);
        if (!is_moving) {
            // Значит до этого лифт не двигался
            moveTo();
        }
    }
}

void QElevator::HandleDispatcherCall()
{
}

void QElevator::HandleCloseDoors()
{
}

void QElevator::HandleOpenDoors()
{
}

void QElevator::HandleSwitchOnOff(bool is_on)
{
    if (is_on && !this->is_on) {
        // То нужно включить лифт:
        initConnections();
        this->is_on = true;
        this->is_blocked = false;
    }

    if (!is_on && this->is_on) {
        // То нужно выключить лифт:
        ranked_floors.clear();
        emit TaskListChanged(ranked_floors);
        destroyConnections();
        this->is_on = false;
        this->is_blocked = true;
        is_moving = false;
    }
}

void QElevator::slotOneFloorMoved()
{
    if (is_on) {
        int one_step = 0;
        if (ranked_floors.at(0) != current_floor) {
            one_step = ranked_floors.at(0) - current_floor > 0 ? 1 : -1;
        }
        current_floor += one_step;
        emit NewFloorReached(current_floor);
        if (current_floor == ranked_floors.at(0)) {
            // Значит задание только что было выполнено
            onMovedFinished();
        } else {
            moveTo();
        }
    }
}


void QElevator::initConnections()
{
    // TODO: связать сигналы со слотами всех устройст
}

// Разрыв всех соединений
void QElevator::destroyConnections()
{
    // TODO: разрушить установленные соединения
}

void QElevator::onMovedFinished()
{
    ranked_floors.pop_front();
    emit TaskListChanged(ranked_floors);
    is_moving = false;
    // На случай, если ещё есть задания:
    moveTo();
}

void QElevator::moveTo()
{
    if (!ranked_floors.empty() && !is_blocked && is_on) {
        // Значит ещё есть задания для выполения
        // Тут на самом деле происходит движение и при этом отправляется сигнал
        // о перемещении на очередной этаж, но для простоты нашего MVP:
        is_moving = true;
        QTimer::singleShot(1000, this, SLOT(slotOneFloorMoved()));
    }
}
