#ifndef VECTOR2I_HPP
#define VECTOR2I_HPP

#include <iostream>

#include "Enum.hpp"

namespace pm {


    class Vector2i {
        public:
            Vector2i();
            Vector2i(int x, int y);

            int getX() const;
            int getY() const;

            void setX(int x);
            void setY(int y);

            void print(pmEnum mode = PM_PRINT_DEFAULT) const;
        
        private:
            int x;
            int y;
    };
}

#endif // VECTOR2I_HPP
