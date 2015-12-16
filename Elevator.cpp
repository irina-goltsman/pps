#include <Elevator.h>

ConcreteStupidRanker::Rank(int current_floor, int direction,
                           QVector<int> *ranked_floors, void new_floor)
{
    ranked_floors->append(new_floor);
}
