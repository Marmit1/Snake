#ifndef
#define

#include <utility>
#include <vector>
#include <deque>

namespace Snake{

    enum class DIRECTION{
        UP, DOWN, LEFT, RIGHT,
    };

    typedef std::pair<std::size_t, std::size_t> Coordinates2D;
    using Coordinates2D.first Coordinates2D.x;
    using Coordinates2D.second Coordinates2D.y;

    class Bend{
    private:
        Coordinates2D coordinates_;
    public:
        Bend(Coordinates2D coordinates) : coordinates_(coordinates){}
    };

    typedef vector<Bend> Bends;

    //TODO - klasa Segment z polami Coords2D(opcjonalnie) i (już na pewno - prawie) is_bend_
    //w zależności od is_bend_ destruktor będzie usuwał z pola bends_ benda
    // WAŻNE!!! - opcja lepsza - typedef na to samo i wartości is not bend albo is bend
    class Segment{
        Coordinates2D coordinates_;
        bool is_bend_;
    public:
        Segment(Coordinates2D coordinates, bool is_bend=false): coordinates_(coordinates), is_bend_(is_bend){}
        bool is_bend() { return is_bend_; }
        Coordinates2D get_coordinates(){ return coordinates_; }
    };

    class Snake{
    private:
        std::size_t minLength;
        Coordinates2D headCoordinates_;
        Coordinates2D tailCoordinates_;
        DIRECTION headOrientation_;
        DIRECTION tailOrientation;
        Bends bends_;
        //TODO - pole segments_ - kolejka dwukierunkowa, najlepiej elementy osobnej klasy Segment
        std::deque<Segment> segments_;

    public:
        Snake(DIRECTION orientation=DIRECTION::UP, Coordinates2D headCoordinates=Coordinates2D({0,3}),
                std::size_t size=3) :
            headOrientation_(orientation), tailOrientation(orientation), headCoordinates_(headCoordinates) {
            //TODO - inicjalizacja pola segments_ w zależności od długości i kierunku początkowego
            switch(orientation){
                case DIRECTION:UP:
                    for(std::size_t i{0}; i<size; ++i){
                        segments_.push_back(Segment({headCoordinates.x, headCoordinates.y-i}));
                    }
                    break;
                case DIRECTION::DOWN:
                    for(std::size_t i{0}; i<size; ++i){
                        segments_.push_back(Segment({headCoordinates.x, headCoordinates.y+i}));
                    }
                    break;
                case DIRECTION::LEFT:
                    for(std::size_t i{0}; i<size; ++i){
                        segments_.push_back(Segment({headCoordinates.x+i, headCoordinates.y}));
                    }
                    break;
                case DIRECTION::RIGHT:
                    for(std::size_t i{0}; i<size; ++i){
                        segments_.push_back(Segment({headCoordinates.x-i, headCoordinates.y}));
                    }
                    break;
            }
        }
        void move(DIRECTION direction){
            switch (direction) {
                case DIRECTION::UP:
                    ++headCoordinates_.y;
                    break;
                case DIRECTION:DOWN:
                    --headCoordinates_.y;
                    break;
                case DIRECTION:LEFT:
                    --headCoordinates_.x;
                    break;
                case DIRECTION::RIGHT:
                    ++headCoordinates_.x;
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
                    ++tailCoordinates_.y;
                    break;
                case DIRECTION::DOWN:
                    --tailCoordinates_.y;
                    break;
                case DIRECTION::LEFT:
                    --tailCoordinates_.x;
                    break;
                case DIRECTION::RIGHT:
                    ++tailCoordinates_.x;
                    break;
            }
        }
    };
}

#endif