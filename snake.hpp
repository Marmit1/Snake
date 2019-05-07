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

    //TODO - klasa Segment z polami Coords2D(opcjonalnie) i (już na pewno - prawie) is_bend_
    //w zależności od is_bend_ destruktor będzie usuwał z pola bends_ benda
    // WAŻNE!!! - opcja lepsza - typedef na to samo i wartości is not bend albo is bend

    class Snake{
    private:
        std::size_t minLength;
        Coordinates2D headCoordinates_;
        Coordinates2D tailCoordinates_;
        DIRECTION headOrientation_;
        DIRECTION tailOrientation;
        Bends bends_;
        //TODO - pole segments_ - kolejka dwukierunkowa, najlepiej elementy osobnej klasy Segment
    public:
        Snake(DIRECTION orientation=DIRECTION::UP, Coordinates2D headCoordinates=Coordinates2D({0,3}),
                std::size_t size=3) :
            headOrientation_(orientation), tailOrientation(orientation), headCoordinates_(headCoordinates) {
            //TODO - inicjalizacja pola segments_ w zależności od długości i kierunku początkowego
        }
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