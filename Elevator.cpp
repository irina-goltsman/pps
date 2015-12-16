#include <Elevator.h>

ConcreteStupidRanker::Rank(int current_floor,
                           QVector<int> *ranked_floors, int new_floor)
{
    ranked_floors->append(new_floor);
}


void QElevator::HandleAddFloorTask(int floor)
{
    ranker.Rank(current_floor,ranked_floors, floor);
}

void QElevator::onMovedFinished()
{
    ranked_floors.pop_front();
}
