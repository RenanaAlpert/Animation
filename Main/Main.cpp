#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <thread>
#include <chrono>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
//#include "Rectangle.h"
#include "Group.h"
#include "colored_canvas.hpp"
#include "AnimationStep.h"
#include "Animation.h"

struct MoveRight { void operator()(experis::Shape& a_shape) { a_shape.MoveBy(1, 0); } };
struct MoveDown { void operator()(experis::Shape& a_shape) { a_shape.MoveBy(0, 1); } };

int main()
{
    {
        using namespace experis;
       // Line l{'X', short(2), short(4), short(2), short(10)};
       // ascii::ColoredCanvas c{20, 20};

       // l.SetBg(Shape::Color::YELLOW);
       // l.SetFg(Shape::Color::BLACK);
       // /*l.Draw(c);
       // c.Print(std::cout);*/

       // Circle cir{'o', short(2), short(2), 2};

       // cir.SetBg(Shape::Color::BLUE);
       // cir.SetFg(Shape::Color::WHITE);
       // /*cir.Draw(c);
       // c.Print(std::cout);*/

       // /*Rectangle r{'X', short(2), short(4), short(5), short(10)};
       // r.SetBg(Shape::Color::BLUE);
       // r.SetFg(Shape::Color::WHITE);
       // r.Draw(c);
       // c.Print(std::cout);*/

       ///* Group g{'*'};
       // g.Add<Line>(short(2), short(4), short(2), short(10));
       // g.Add<Circle>(short(2), short(2), 2);
       // g.Draw(c);
       // c.Print(std::cout);*/

     //   AnimationStep<MoveRight>* animStep = new AnimationStep<MoveRight>{l, 20, MoveRight{}};
     //   Animation anim;
     //   anim.Add(animStep);
     //   while (anim.HasAnimation())
	    //{
		   // ascii::ColoredCanvas canvas{80, 25};
		   // l.Draw(canvas);
		   // canvas.Print(std::cout);
		   // ++anim; // This will perform MoveRight the first 50 times and then MoveDown 20 times
     //       std::this_thread::sleep_for(std::chrono::milliseconds(500));
	    //}


        Group man{'*'};
        
        man.Add<Circle>(short(4), short(3), 1);
        man.Add<Line>(short(4), short(5), short(4), short(8));
        man.Add<Line>(short(3), short(5), short(2), short(6));
        man.Add<Line>(short(5), short(5), short(6), short(6));
        man.Add<Line>(short(3), short(9), short(2), short(10));
        man.Add<Line>(short(5), short(9), short(6), short(10));

        Group row('#');
        row.Add<Line>(short(0), short(0), short(100), short(0));
        row.Add<Line>(short(0), short(12), short(70), short(12));
        row.Add<Line>(short(100), short(0), short(100), short(50));
        row.Add<Line>(short(70), short(12), short(70), short(50));

        /*ascii::ColoredCanvas canvas{150, 41};
        man.Draw(canvas);
        row.Draw(canvas);
        canvas.Print(std::cout);*/

        AnimationStep<MoveRight>* animStepRight = new AnimationStep<MoveRight>{man, 80, MoveRight{}};
        AnimationStep<MoveDown>* animStepLeft = new AnimationStep<MoveDown>{man, 30, MoveDown{}};
        Animation anim;
        anim.Add(animStepRight);
        anim.Add(animStepLeft);
        while (anim.HasAnimation())
        {
            ascii::ColoredCanvas canvas{110, 30};
            man.Draw(canvas);
            row.Draw(canvas);
            canvas.Print(std::cout);
            ++anim; // This will perform MoveRight the first 50 times and then MoveDown 20 times
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
    _CrtDumpMemoryLeaks();
}