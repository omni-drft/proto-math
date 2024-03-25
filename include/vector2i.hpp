#ifndef VECTOR2I_HPP
#define VECTOR2I_HPP

#include <iostream>

namespace pm {
    class Vector2i {
        public:
            Vector2i();
            Vector2i(int x, int y);

            int getX() const;
            int getY() const;

            void setX(int x);
            void setY(int y);

            void print() const;
        
        private:
            int x;
            int y;
    };
}

#endif // VECTOR2I_HPP
