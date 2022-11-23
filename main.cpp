#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float p = 0, c1 = 0, c2 = 900 ;
//the initial values of objects and variables
void init(void){

    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
//setting up 2d view region (left,right,button,top)
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

void Sky(){
    glColor3f(0.3,0.5,0.70);
    //method to create 4 vertices shape
    glBegin(GL_QUADS);
    glVertex2i(0,684);
    glVertex2i(902,684);
    glVertex2i(902,0);
    glVertex2i(0,0);
    glEnd();
}



void Home (){


    glColor3f(0.5,0.5,0.5);
    //method to create 4 vertices shape
//roof of the building
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();
//base of the building
    glColor3f(0.3,0.3,0.30);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();


    //middle building part
    glColor3f(0.75,0.79,0.73);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();

    //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
}
// method for Drawing circles using triangle fan
void drawCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 50;
    GLfloat twicePi = 2.0f*3.14;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for(i = 0; i <= triangleAmount; i++){
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}




void factory (){



//building two base
    glColor3ub(170,170,170);
    glBegin(GL_QUADS);
    glVertex2i(500,250);
    glVertex2i(617,250);
    glVertex2i(617,390);
    glVertex2i(500,390);
    glEnd();
//factory chimney
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(526,390);
    glVertex2i(500,390);
    glVertex2i(500,423);
    glVertex2i(526,423);
    glEnd();


}

void Door(){


    // door
    glColor3f(255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(550,257);
    glVertex2i(570,257);
    glVertex2i(570,300);
    glVertex2i(550,300);
    glEnd();
}



void Sun(){
    glColor3f(0.9,0.9,0);
    drawCircle(624.0f,615.0f,40.0f);
}



void Road(){
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(1000,180);
    glVertex2i(1000,0);
    glVertex2i(0,0);
    glEnd();
    glPopMatrix();
// for loop to draw the lines in the road
    for(int i=0;i<120*8;i+=120){
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,95);
        glVertex2i(35+i,95);
        glVertex2i(35+i,100);
        glVertex2i(0+i,100);
        glEnd();
        glPopMatrix();
    }
}



void BetweenRoadAndBuldings(){
    glPushMatrix();
    glColor3ub(0,150,0);
    glBegin(GL_QUADS);
    glVertex3f(0.0,205.0,0.0);
    glVertex3f(1000.0,205.0,0.0);
    glVertex3f(1000.0,258.0,0.0);
    glVertex3f(0.0,258.0,0.0);
    glEnd();
    glPopMatrix();
}


void Cloud(){
    glColor3f(1,1,1);

    //cloud 1
    drawCircle(200.0f,610.0f,25.0f);
    drawCircle(170.0f,615.0f,38.0f);
    drawCircle(139.0f,610.0f,35.0f);
    drawCircle(111.0f,598.0f,25.0f);


    // cloud 2
    drawCircle(597.0f,590.0f,20.0f);
    drawCircle(572.0f,600.0f,30.0f);
    drawCircle(539.0f,600.0f,35.0f);
    drawCircle(502.0f,590.0f,23.0f);

    glutPostRedisplay();
}



void Boat(){
    glColor3f(0.6 ,0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (902, 205);
    glVertex2f (812, 205);
    glVertex2f (822, 195);
    glVertex2f (892, 195);
    glEnd();
//the lower part
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f (872, 215);
    glVertex2f (842, 215);
    glVertex2f (837, 205);
    glVertex2f (877, 205);
    glEnd();



    glutPostRedisplay();
}

void Car1(){
    //body
    glColor3f(1 ,0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (c1, 90);
    glVertex2f (c1+80, 90);
    glVertex2f (c1+80, 65);
    glVertex2f (c1, 65);
    glEnd();

    //tire1
    glColor3ub(48,48,46);
    drawCircle(c1+20,65,12);
    glColor3ub(255,255,255);
    drawCircle(c1+20,65,7);
    glColor3ub(0,0,0);

    //tire2
    glColor3ub(48,48,46);
    drawCircle(c1+60,65,12);
    glColor3ub(255,255,255);
    drawCircle(c1+60,65,7);
    glColor3ub(0,0,0);

    if(c1<=950){
        c1 = c1+0.5;
    }
    else{
        c1 = 0;
    }

    glutPostRedisplay();
}

void Car2(){
    //body
    glColor3f(0 , 0, 1);
    glBegin(GL_QUADS);
    glVertex2f (c2, 140);
    glVertex2f (c2-80, 140);
    glVertex2f (c2-80, 115);
    glVertex2f (c2, 115);
    glEnd();

    //tire1
    glColor3ub(48,48,46);
    drawCircle(c2-20,115,12);
    glColor3ub(255,255,255);
    drawCircle(c2-20,115,7);
    glColor3ub(0,0,0);

    //tire2
    glColor3ub(48,48,46);
    drawCircle(c2-60,115,12);
    glColor3ub(255,255,255);
    drawCircle(c2-60,115,7);
    glColor3ub(0,0,0);

    if(c2>=0){
        c2 = c2-0.5;
    }
    else{
        c2 = 900;
    }

    glutPostRedisplay();
}

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Home();
    factory ();
    Door();
    Road();
    BetweenRoadAndBuldings();
    Sun();
    Cloud();
    Boat();
    Car1();
    Car2();
    glFlush (); //push everything through the graphics card (refresh)
    glutSwapBuffers(); //to display image in double layer buffer
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("mariamnasser20102401/linabahaa20103667");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
