/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MATHHELPER_HEADER
#define MATHHELPER_HEADER

#include "Vector.hpp"


namespace FlockingSystem
{

    class MathHelper
    {

    public:

        static float magnitude(toolkit::Vector2f* vec)
        {
            return sqrtf(powf((*vec)[0], 2) + powf((*vec)[1], 2));
        }

        static void normalize(toolkit::Vector2f* vec)
        {
            float l = 1 / magnitude(vec);

            (*vec)[0] *= l;
            (*vec)[1] *= l;
        }

        static float distance(toolkit::Vector2f& A, toolkit::Vector2f& B)
        {
            toolkit::Vector2f direction(
                {
                    B[0] - A[0],
                    B[1] - A[1],
                
                });


            return magnitude(&direction);
        }

        static toolkit::Vector2f getDirection(toolkit::Vector2f& A, toolkit::Vector2f& B)
        {
            toolkit::Vector2f direction(
                {
                    B[0] - A[0],
                    B[1] - A[1],

                });


            return direction;
        }
        
        static float sqrtMagnitude(toolkit::Vector2f A)
        {
           
            return sqrtf( magnitude(&A) );
        }
        

        static float generateRandom(double M, double N)
        {
            return (float)(M + (rand() / (RAND_MAX / (N - M))));
        }
        
        static void setMag(toolkit::Vector2f& vec, float newMag)
        {
            float mag = magnitude(&vec);

            vec[0] = vec[0] * newMag / mag;
            vec[1] = vec[1] * newMag / mag;
        } 
        
        static void limit(toolkit::Vector2f& vec, float max)
        {
            float mag = magnitude(&vec);

            if (mag > max)
            {
                setMag(vec, max);
            }

        }
        


    };

}

#endif
