#ifndef
#define

#include <utility>
#include <vector>

namespace Snake{

    enum class DIRECTION{
        UP, DOWN, LEFT, RIGHT,
    };

    typedef std::pair<std::size_t, std::size_t> Coordinates2D;

    class Bend{
    private:
        Coordinates2D coordinates_;
    public:
        Bend(Coordinates2D coordinates) : coordinates_(coordinates){}
    };

    typedef vector<Bend> Bends;

    class Snake{
    private:
        std::size_t minLength;
        Coordinates2D headCoordinates_;
        Coordinates2D tailCoordinates_;
        DIRECTION headOrientation_;
        DIRECTION tailOrientation;
        Bends bends_;
    public:
        void move(DIRECTION direction){
            switch (direction) {
                case DIRECTION::UP:
                    ++headCoordinates_.second;
                    break;
                case DIRECTION:DOWN:
                    --headCoordinates_.second;
                    break;
                case DIRECTION:LEFT:
                    --headCoordinates_.first;
                    break;
                case DIRECTION::RIGHT:
                    ++headCoordinates_.first;
                    break;
            }
            if(headOrientation_ != direction) {
                bends_.push_back(Bend(headCoordinates_));
            }
            for(std::size_t i = bends_.begin(); i < bends_.end(); ++i){
                if(i.coordinates_ == tailCoordinates_){
                    bends_.erase(i);
                }
            }
            switch(tailOrientation){
                case DIRECTION::UP:
                    ++tailCoordinates_.second;
                    break;
                case DIRECTION::DOWN:
                    --tailCoordinates_.second;
                    break;
                case DIRECTION::LEFT:
                    --tailCoordinates_.first;
                    break;
                case DIRECTION::RIGHT:
                    ++tailCoordinates_.first;
                    break;
            }
        }
    };
}

#endif