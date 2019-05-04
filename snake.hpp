#ifndef
#define

#include <utility>

namespace Snake{

    enum class DIRECTION{
        UP, DOWN, LEFT, RIGHT,
    };

    typedef std::pair<std::size_t, std::size_t> Coordinates2D;
    using Coordinates2D.first = x;
    using Coordinates2D.second = y;

    class Snake{
    private:
        Coordinates2D headCoordinates;
    public:
        void move(DIRECTION direction){
            switch (direction) {
                case DIRECTION::UP:
                    ++y;
                case DIRECTION:DOWN:
                    --y;
                case DIRECTION:LEFT:
                    --x;
                case DIRECTION::RIGHT:
                    ++x;
            }
        }
    };
}

#endif