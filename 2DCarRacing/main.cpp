#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include<math.h>

//Game Speed
int FPS = 50;
//Game Track
int start=0;
int gv=0;
int level = 0;

//Track Score
int score = 0;

//Form move track
int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;

int carDivTopMost = 0;
///move front page car
int moveright_Ftire = 0;
int moveright_Stire = 0;
int moveleft_Ftire = 0;
int moveleft_Stire = 0;
int middle_move = 0;
int CAR=0;
int lwindow=0;
int frontwindow=0;
int upwindow=0;
int backwindow=0;

int carDivMdl = 0;
//For Card Left / RIGHT
int vertex = 0 ;
///move tree
int move_tree0 = 0;
int move_tree1 = 0;
int move_tree2 = 0;
int move_tree3 = 0;
int move_tree4 = 0;
int move_tree5 = 0;
int move_tree6 = 0;
int move_tree7 = 0;

//Car Coming
int car1 = 0;
int vertex1=0;
int car2 = +35;
int vertex2=0;
int car3 = +70;
int vertex3=0;

///Main Car move
int vertexy=0;

///house
int Left_Build = 0;
int Left_Build_Gate = 0;
int Left_Build_G_border = 0;
int Left_Build_L_Wi = 0;
int Left_Build_R_Wi =0;
int Left_Build_L_up1_Wi=0;
int Left_Build_L_up2_Wi=0;
int Left_Build_R_up1_Wi=0;
int Left_Build_R_up2_Wi=0;
int Left_Build_R_up3_Wi=0;

///For Display TEXT
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_HELVETICA_18;

char s[30];
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}




void startGame(){

    //Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(40,0);
    glVertex2f(40,120);
    glVertex2f(100,120);
    glVertex2f(100,0);
    glEnd();

    //Road Left Border
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(40,0);
    glVertex2f(40,110);
    glVertex2f(43,110);
    glVertex2f(43,0);
    glEnd();

    //Road Right Border
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(97,0);
    glVertex2f(97,120);
    glVertex2f(100,120);
    glVertex2f(100,0);
    glEnd();

    //Road Middel Border
      //TOP
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(68,roadDivTop+80);
    glVertex2f(68,roadDivTop+100);
    glVertex2f(72,roadDivTop+100);
    glVertex2f(72,roadDivTop+80);
    glEnd();
    roadDivTop--;
    if(roadDivTop<-100){
        roadDivTop =20;
        ///score++;
    }
     //Midle
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(68,roadDivMdl+40);
    glVertex2f(68,roadDivMdl+60);
    glVertex2f(72,roadDivMdl+60);
    glVertex2f(72,roadDivMdl+40);
    glEnd();



    roadDivMdl--;
    if(roadDivMdl<-60){
        roadDivMdl =60;
        ///score++;
    }
        //Bottom
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(68,roadDivBtm+0);
    glVertex2f(68,roadDivBtm+20);
    glVertex2f(72,roadDivBtm+20);
    glVertex2f(72,roadDivBtm+0);
    glEnd();
    roadDivBtm--;
    if(roadDivBtm<-20){
        roadDivBtm=100;
        ///score++;
    }


    //Print Score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(0,0,0);
    renderBitmapString(120,95,(void *)font3,buffer);

        if(score % 5 == 0){
        int last = score /5;
        if(last!=level){
            level = score /5;
            FPS=FPS+5;

        }
    }
    ///MAIN car

///Front tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+45.5,vertexy+8);
    glVertex2f(vertex+52.5,vertexy+8);
    glVertex2f(vertex+52.5,vertexy+7);
    glVertex2f(vertex+45.5,vertexy+7);
    glEnd();
///Back Tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+45.5,vertexy+2);
    glVertex2f(vertex+52.5,vertexy+2);
    glVertex2f(vertex+52.5,vertexy+3);
    glVertex2f(vertex+45.5,vertexy+3);
    glEnd();
///Car Body
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+46,vertexy+1);
    glVertex2f(vertex+46,vertexy+8);
    glVertex2f(vertex+47,vertexy+9);
    glVertex2f(vertex+51,vertexy+9);
    ///glColor3f(0.000, 0.545, 0.545);

    //glVertex2f(vertex+48,10);
    glVertex2f(vertex+52,vertexy+8);
    glVertex2f(vertex+52,vertexy+1);
    glEnd();
///Front window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+47,vertexy+8);
    glVertex2f(vertex+51,vertexy+8);
    glVertex2f(vertex+51,vertexy+7);
    glVertex2f(vertex+47,vertexy+7);
    glEnd();
///Right window
        glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+51,vertexy+6.5);
    glVertex2f(vertex+51,vertexy+3);
    glVertex2f(vertex+49.5,vertexy+3.5);
    glVertex2f(vertex+49.5,vertexy+6);
    glEnd();
///Left Window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+47,vertexy+6.5);
    glVertex2f(vertex+47,vertexy+3);
    glVertex2f(vertex+48.5,vertexy+3.5);
    glVertex2f(vertex+48.5,vertexy+6);
    glEnd();
///Middle
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+48.5,vertexy+6);
    glVertex2f(vertex+48.5,vertexy+3.5);
    glVertex2f(vertex+49.5,vertexy+3.5);
    glVertex2f(vertex+49.5,vertexy+6);
    glEnd();
///Back Window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(vertex+47,vertexy+2);
    glVertex2f(vertex+51,vertexy+2);
    glVertex2f(vertex+51,vertexy+2.8);
    glVertex2f(vertex+47,vertexy+2.8);
    glEnd();

///Opposite car 1

///Front tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex1+46-2,car1+100-4);
    glVertex2f(vertex1+46-2,car1+100-6);
    glVertex2f(vertex1+50+2,car1+100-6);
    glVertex2f(vertex1+50+2,car1+100-4);
    glEnd();
///Back Tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex1+46-2,car1+100);
    glVertex2f(vertex1+46-2,car1+100-2);
    glVertex2f(vertex1+50+2,car1+100-2);
    glVertex2f(vertex1+50+2,car1+100);
    glEnd();
///Body
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex1+46,car1+100);
    glVertex2f(vertex1+46,car1+100-7);
    glVertex2f(vertex1+48,car1+100-9);
    glVertex2f(vertex1+50,car1+100-7);
    glVertex2f(vertex1+50,car1+100);
    glEnd();
    car1--;
    if(car1<-110){
        car1=0;
        vertex1=vertex;
        score++;
    }
///KIll check car1
    if((abs(vertex-vertex1)<5) && (car1+100<15)){
            start = 0;
            gv=1;

    }

///Opposite car 2

///Front Tire
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex2+46-2,car2+100-4);
    glVertex2f(vertex2+46-2,car2+100-6);
    glVertex2f(vertex2+50+2,car2+100-6);
    glVertex2f(vertex2+50+2,car2+100-4);
    glEnd();
///Back tire
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex2+46-2,car2+100);
    glVertex2f(vertex2+46-2,car2+100-2);
    glVertex2f(vertex2+50+2,car2+100-2);
    glVertex2f(vertex2+50+2,car2+100);
    glEnd();
///Body
    glColor3f(0.294, 0, 0.510);
    glBegin(GL_POLYGON);
    glVertex2f(vertex2+46,car2+100);
    glVertex2f(vertex2+46,car2+100-7);
    glVertex2f(vertex2+48,car2+100-9);
    glVertex2f(vertex2+50,car2+100-7);
    glVertex2f(vertex2+50,car2+100);
    glEnd();
    car2--;
    if(car2<-110){
        car2=0;
        vertex2=vertex;
        score++;
    }
///KIll check car2
    if((abs(vertex-vertex2)<5) && (car2+100<15)){
            start = 0;
            gv=1;
    }


///Opposite car 3

///Front Tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex3+46-2,car3+100-4);
    glVertex2f(vertex3+46-2,car3+100-6);
    glVertex2f(vertex3+50+2,car3+100-6);
    glVertex2f(vertex3+50+2,car3+100-4);
    glEnd();
///Back tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex3+46-2,car3+100);
    glVertex2f(vertex3+46-2,car3+100-2);
    glVertex2f(vertex3+50+2,car3+100-2);
    glVertex2f(vertex3+50+2,car3+100);
    glEnd();
///Body
    glColor3f(1, 0.271, 0);
    glBegin(GL_POLYGON);
    glVertex2f(vertex3+46,car3+100);
    glVertex2f(vertex3+46,car3+100-7);
    glVertex2f(vertex3+48,car3+100-9);
    glVertex2f(vertex3+50,car3+100-7);
    glVertex2f(vertex3+50,car3+100);
    glEnd();
    car3--;
    if(car3<-110){
        car3=0;
        vertex3=vertex;
        score++;
    }

///KIll check car3
    if((abs(vertex-vertex3)<5) && (car3+100<15)){
            start = 0;
            gv=1;

    }

///Tree
///Tree left Lower
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(5,move_tree0+15);
    glVertex2f(25,move_tree0+15);
    glVertex2f(15,move_tree0+30);
    glEnd();

    move_tree0--;
    if(move_tree0<-100){
        move_tree0 =100;

    }

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(12.5,move_tree1+15);
    glVertex2f(17.5,move_tree1+15);
    glVertex2f(17.5,move_tree1+5);
    glVertex2f(12.5,move_tree1+5);

    glEnd();
    move_tree1--;
    if(move_tree1<-100){
        move_tree1 =100;

    }
///Tree left Upper
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(5,move_tree2+80);
    glVertex2f(25,move_tree2+80);
    glVertex2f(15,move_tree2+95);
    glEnd();
    move_tree2--;
    if(move_tree2<-100){
        move_tree2 =100;
    }

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(12.5,move_tree3+80);
    glVertex2f(17.5,move_tree3+80);
    glVertex2f(17.5,move_tree3+70);
    glVertex2f(12.5,move_tree3+70);

    glEnd();

     move_tree3--;
    if(move_tree3<-100){
        move_tree3 =100;
    }

///Tree right Lower
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(110,move_tree4+15);
    glVertex2f(130,move_tree4+15);
    glVertex2f(120,move_tree4+30);
    glEnd();

     move_tree4--;
    if(move_tree4<-100){
        move_tree4 =80;
    }

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(117.5,move_tree5+15);
    glVertex2f(122.5,move_tree5+15);
    glVertex2f(122.5,move_tree5+5);
    glVertex2f(117.5,move_tree5+5);

    glEnd();

     move_tree5--;
    if(move_tree5<-100){
        move_tree5 =80;
    }

///Tree Right Upper
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(110,move_tree6+80);
    glVertex2f(130,move_tree6+80);
    glVertex2f(120,move_tree6+95);
    glEnd();

     move_tree6--;
    if(move_tree6<-100){
        move_tree6 =80;
    }

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(117.5,move_tree7+80);
    glVertex2f(122.5,move_tree7+80);
    glVertex2f(122.5,move_tree7+70);
    glVertex2f(117.5,move_tree7+70);

    glEnd();
     move_tree7--;
    if(move_tree7<-100){
        move_tree7 =80;
    }

///Left Building
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(2.5,Left_Build+40);
    glVertex2f(37.5,Left_Build+40);
    glVertex2f(37.5,Left_Build+55);
    glVertex2f(2.5,Left_Build+55);

    glEnd();

     Left_Build--;
    if(Left_Build<-100){
        Left_Build =100;
    }


///Left Building Gate
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(15,Left_Build_Gate+40);
    glVertex2f(25,Left_Build_Gate+40);
    glVertex2f(25,Left_Build_Gate+45);
    glVertex2f(15,Left_Build_Gate+45);

    glEnd();

     Left_Build_Gate--;
    if(Left_Build_Gate<-100){
        Left_Build_Gate =100;
    }
///Left Building Gate border
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(20,Left_Build_G_border+40);
    glVertex2f(20,Left_Build_G_border+45);


    glEnd();
     Left_Build_G_border--;
    if(Left_Build_G_border<-100){
        Left_Build_G_border =100;
    }
///Left Building Left Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(5,Left_Build_L_Wi+42);
    glVertex2f(10,Left_Build_L_Wi+42);
    glVertex2f(10,Left_Build_L_Wi+45);
    glVertex2f(5,Left_Build_L_Wi+45);

    glEnd();

     Left_Build_L_Wi--;
    if(Left_Build_L_Wi<-100){
        Left_Build_L_Wi =100;
    }
///Left Building Right Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(30,Left_Build_R_Wi+42);
    glVertex2f(35,Left_Build_R_Wi+42);
    glVertex2f(35,Left_Build_R_Wi+45);
    glVertex2f(30,Left_Build_R_Wi+45);

    glEnd();
     Left_Build_R_Wi--;
    if(Left_Build_R_Wi<-100){
        Left_Build_R_Wi =100;
    }

///Left Building Left upper1 Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(4, Left_Build_L_up1_Wi+50);
    glVertex2f(9, Left_Build_L_up1_Wi+50);
    glVertex2f(9, Left_Build_L_up1_Wi+53);
    glVertex2f(4, Left_Build_L_up1_Wi+53);

    glEnd();

     Left_Build_L_up1_Wi--;
    if(Left_Build_L_up1_Wi<-100){
        Left_Build_L_up1_Wi =100;
    }

///Left Building Left upper2 Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(11, Left_Build_L_up2_Wi+50);
    glVertex2f(16, Left_Build_L_up2_Wi+50);
    glVertex2f(16, Left_Build_L_up2_Wi+53);
    glVertex2f(11, Left_Build_L_up2_Wi+53);

    glEnd();

     Left_Build_L_up2_Wi--;
    if(Left_Build_L_up2_Wi<-100){
        Left_Build_L_up2_Wi =100;
    }
///Left Building Right upper1 Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(18,Left_Build_R_up1_Wi+50);
    glVertex2f(23,Left_Build_R_up1_Wi+50);
    glVertex2f(23,Left_Build_R_up1_Wi+53);
    glVertex2f(18,Left_Build_R_up1_Wi+53);

    glEnd();

     Left_Build_R_up1_Wi--;
    if(Left_Build_R_up1_Wi<-100){
        Left_Build_R_up1_Wi =100;
    }
///Left Building Right upper2 Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(25,Left_Build_R_up2_Wi+50);
    glVertex2f(30,Left_Build_R_up2_Wi+50);
    glVertex2f(30,Left_Build_R_up2_Wi+53);
    glVertex2f(25,Left_Build_R_up2_Wi+53);

    glEnd();

     Left_Build_R_up2_Wi--;
    if(Left_Build_R_up2_Wi<-100){
        Left_Build_R_up2_Wi =100;
    }
///Left Building Right upper3 Window
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(32,Left_Build_R_up3_Wi+50);
    glVertex2f(36,Left_Build_R_up3_Wi+50);
    glVertex2f(36,Left_Build_R_up3_Wi+53);
    glVertex2f(32,Left_Build_R_up3_Wi+53);

    glEnd();

     Left_Build_R_up3_Wi--;
    if(Left_Build_R_up3_Wi<-100){
        Left_Build_R_up3_Wi =100;
    }


    }




void fristDesign(){


    ///CAR
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(CAR+30,65);
    glVertex2f(CAR+80,65);
    glVertex2f(CAR+85,70);
    glVertex2f(CAR+85,75);
    glVertex2f(CAR+80,80);
    glVertex2f(CAR+30,80);
    glVertex2f(CAR+25,77);
    glVertex2f(CAR+25,68);
    glEnd();
         CAR++;
    if(CAR > 120){
        CAR = -80;
        //score++;
    }
///Back window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(backwindow+30,70);
    glVertex2f(backwindow+35,67);
    glVertex2f(backwindow+35,78);
    glVertex2f(backwindow+30,75);
    glEnd();
          backwindow++;
    if(backwindow > 120){
        backwindow = -80;
        //score++;
    }
///Front window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(frontwindow+80,70);
    glVertex2f(frontwindow+80,75);
    glVertex2f(frontwindow+75,78);
    glVertex2f(frontwindow+75,67);
    glEnd();
      frontwindow++;
    if(frontwindow > 120){
        frontwindow = -80;
        //score++;
    }
///Upper Window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(upwindow+40,78);
    glVertex2f(upwindow+70,78);
    glVertex2f(upwindow+67,74);
    glVertex2f(upwindow+43,74);
    glEnd();
     upwindow++;
    if(upwindow > 120){
        upwindow = -80;
        //score++;
    }
///Lower Window
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(lwindow+40,67);
    glVertex2f(lwindow+70,67);
    glVertex2f(lwindow+67,71);
    glVertex2f(lwindow+43,71);
    glEnd();
      lwindow++;
    if(lwindow > 120){
        lwindow = -80;
        //score++;
    }

 ///Middle
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(middle_move+43,71);
    glVertex2f(middle_move+67,71);
    glVertex2f(middle_move+67,74);
    glVertex2f(middle_move+43,74);
    glEnd();
      middle_move++;
    if(middle_move > 120){
        middle_move = -80;
        //score++;
    }
 ///Right lower tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(moveright_Stire+30,65);
    glVertex2f(moveright_Stire+30,63);
    glVertex2f(moveright_Stire+37,63);
    glVertex2f(moveright_Stire+37,65);
    glEnd();

     moveright_Stire++;
    if(moveright_Stire > 120){
        moveright_Stire = -80;
        //score++;
    }
///Left lower Tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(moveleft_Stire+30,80);
    glVertex2f(moveleft_Stire+30,82);
    glVertex2f(moveleft_Stire+37,82);
    glVertex2f(moveleft_Stire+37,80);
    glEnd();
      moveleft_Stire++;
    if(moveleft_Stire > 120){
        moveleft_Stire = -80;
        //score++;
    }

///Right upper Tire
        glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(moveright_Ftire+80,65);
    glVertex2f(moveright_Ftire+80,63);
    glVertex2f(moveright_Ftire+73,63);
    glVertex2f(moveright_Ftire+73,65);
    glEnd();
     moveright_Ftire++;
    if(moveright_Ftire > 120){
        moveright_Ftire = -80;
        //score++;
    }
///Left first Tire
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(moveleft_Ftire+80,80);
    glVertex2f(moveleft_Ftire+80,82);
    glVertex2f(moveleft_Ftire+73,82);
    glVertex2f(moveleft_Ftire+73,80);
    glEnd();

    moveleft_Ftire++;
    if(moveleft_Ftire > 120){
        moveleft_Ftire = -80;
        //score++;
    }

        ///Text Information in First Page
        if(gv==1){
            glColor3f(1,0,0);
            renderBitmapString(100,54,(void *)font1,"GAME OVER !!!");
            glColor3f(1,0,0);
            char buffer2 [50];
            sprintf (buffer2, "Your Score is : %d", score);
            renderBitmapString(100,50,(void *)font1,buffer2);

        }

        glColor3f(1,1,0);
        renderBitmapString(60,95,(void *)font1,"CAR CRASH");

        glColor3f(0,1,0);
        renderBitmapString(30,50,(void *)font2,"Press ENTER to START");
        renderBitmapString(30,47,(void *)font2,"Press ESC to Exit");

        glColor3f(1,1,1);
        renderBitmapString(30,40,(void *)font3,"Press UP to move up");
        renderBitmapString(30,36,(void *)font3,"Press RIGHT to move Right");
        renderBitmapString(30,32,(void *)font3,"Press LEFT to move Left");


        glColor3f(0,1,1);
        renderBitmapString(30,20,(void *)font3,"Group Member:");
        renderBitmapString(50,15,(void *)font3,"MORSHAD, MD. SARWAR(15-29680-2)");
        renderBitmapString(50,10,(void *)font3,"MOZUMDAR, MD. RABIUZZAMAN(15-29592-2)");
        renderBitmapString(50,5,(void *)font3,"RAJU,MOHAMMAD IFRAN HOSSAIN(15-29674-2)");


}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(start==1){
        // glClearColor(0.627, 0.322, 0.176,1);

        glClearColor(0.000, 0.392, 0.000,1);
        startGame();
    }

    else{
        fristDesign();
        //glClearColor(0.184, 0.310, 0.310,1);



    }



    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y){
        switch (key) {

        case GLUT_KEY_LEFT:
            if(vertex>=0){
                vertex = vertex - (FPS/10);
                if(vertex<0){
                    vertex=-1;
                }
            }
            break;


        case GLUT_KEY_RIGHT:
            if(vertex<=44){
                vertex = vertex + (FPS/10);
                if(vertex>44){
                    vertex = 45;
                }
            }
            break;

         case GLUT_KEY_DOWN:
             if(vertexy>=0){
                vertexy = vertexy - (FPS/10);
                if(vertexy<0){
                    vertexy=-1;
                }
            }
           //timer(0);
            break;
        case GLUT_KEY_UP:
            if(vertexy<=80){
                vertexy = vertexy + (FPS/10);
                if(vertexy>80){
                    vertexy=81;
                }
            }

            //timer(0);
            break;

        default:
                break;
        }

}

void processKeys(unsigned char key, int x, int y) {

      switch (key)
            {
                case 13:
            if(start==0){
                start = 1;
                gv = 0;
                FPS = 50;
                roadDivTopMost = 0;
                roadDivTop = 0;
                roadDivMdl = 0;
                roadDivBtm = 0;
                vertex = 0 ;
                car1 = 0;
                vertex1=0;
                car2 = +35;
                vertex2=0;
                car3 = +70;
                vertex3=0;
                score=0;
                level=0;
            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700,650);
    glutInitWindowPosition(200,50);
    glutCreateWindow("Car Game");

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );

    glOrtho(0,150,0,100,-1,1);
    glClearColor(0.310, 0.310, 0.310,1);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}
