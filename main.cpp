#include<windows.h>

#include<stdio.h>

#include<GL/glut.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>

#define CIRCLE_RADIUS  0.15f

#define PI 3.14159265358979323846

int eggs_caught = 0, missed_eggs = 0, level_count = 1, points = 0;





int egg_xc, egg_yc;


int basket_x, basket_y;



int a = 600, b = 650;

int s = 0;


int dropped_eggs = 0;

int speed_1 = 1, speed_2 = 1.5, speed_3 = 2, speed_4 = 2.5;

int w = 48, h = 48, t = 10, e = 9, g = 12;

void myinit();

void start_screen(int, int);

void cloud1();

void egg();

void basket(int, int);

void duck(int, int);

void print_score();

void egg_start();

void color();

void score();

void display(void);

void basket_set(int, int);

void myReshape(int, int);

void keys(unsigned char, int, int);

void menu(int);
void drawString1 (void * font, char *s, float x, float y) {

    glRasterPos2f(x, y);

    glColor3f(1, 1, 1);

    for (int i = 0; i < strlen (s); i++)

        glutBitmapCharacter (font, s[i]);

}



void drawString (void * font, int s, int spc, float x, float y) {

    glRasterPos2f(x, y);

    glColor3f(1, 1, 1);

    int k = 0, j = 0;

    while (s > 9) {



        k = s % 10;

        glRasterPos2f((x - (j * spc)), y);

        glutBitmapCharacter (font, 48 + k);

        j++;

        s = s / 10;



    }

    glRasterPos2f((x - (j * spc)), y);

    glutBitmapCharacter (font, 48 + s);

}

void myinit()

{

    glViewport(0, 0, a, b);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, (GLdouble)a, 0, (GLdouble)b);

    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();

}

void start_screen(int i, int j)

{

    int k;

    char cat[4] = "EGG";

    char orr[9] = "Catching";

    char hatch[5] = "Game";

    char made[30] = "Made by: Gurnoor Singh Marok";

    char name1[13] = "Yashul Tyagi";

    char name2[12] = "Hitesh Garg";


    char start[20] = "Press S for start";

    glColor3f(0, 1, 0);

    glRasterPos2i(180, 320);

    for (k = 0; k < 4; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cat[k]);

    glColor3f(1, 1, 1);

    glRasterPos2i(230, 320);

    for (k = 0; k < 9; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, orr[k]);

    glColor3f(1, 0, 0);

    glRasterPos2i(315, 320);

    for (k = 0; k < 5; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hatch[k]);

    glColor3f(1, 1, 0);

    glRasterPos2i(130, 250);

    for (k = 0; k < 30; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, made[k]);

    glColor3f(1, 1, 0);

    glRasterPos2i(213, 220);

    for (k = 0; k < 13; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name1[k]);

    glColor3f(1, 1, 0);

    glRasterPos2i(213, 190);

    for (k = 0; k < 12; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name2[k]);

    glColor3f(1, 1, 0);

    glRasterPos2i(210, 100);


    for (k = 0; k < 20; k++)

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, start[k]);

    glColor3f(1, .5, .5);



}



void sun()

{



    float theta;



    GLfloat angle;

    glLineWidth(1.5);

    glColor3f(1, 0.8, 0);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(500 + 80 * cos(theta) / 2, 600 + 80 * sin(theta) / 2);

    }



    glEnd();

    glFlush();

}

void cloud1()

{



    float theta;



    GLfloat angle;

    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(100 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);

    }



    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(130 + 50 * cos(theta) / 2, 580 + 50 * sin(theta) / 2);

    }

    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(140 + 50 * cos(theta) / 2, 600 + 50 * sin(theta) / 2);

    }

    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(170 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);

    }



    glEnd();

    glFlush();

}



void cloud2()

{

    float theta;

    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(460 + 45 * cos(theta) / 2, 520 + 45 * sin(theta) / 2);

    }



    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(495 + 45 * cos(theta) / 2, 530 + 45 * sin(theta) / 2);

    }



    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(495 + 45 * cos(theta) / 2, 510 + 45 * sin(theta) / 2);

    }



    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(530 + 45 * cos(theta) / 2, 520 + 45 * sin(theta) / 2);

    }



    glEnd();

    glFlush();



}
void cloud3()

{



    float theta;



    GLfloat angle;

    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(300 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);

    }



    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(330 + 50 * cos(theta) / 2, 580 + 50 * sin(theta) / 2);

    }

    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(340 + 50 * cos(theta) / 2, 600 + 50 * sin(theta) / 2);

    }

    glEnd();



    glLineWidth(1.5);

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 360 ; i++)

    {

        theta  = i * PI * i / 180;

        glVertex2f(370 + 50 * cos(theta) / 2, 590 + 50 * sin(theta) / 2);

    }



    glEnd();

    glFlush();

}





void line(int i , int j)

{



    glBegin(GL_QUADS);

    glColor3f(1.0, .5, 0.5);

    glVertex2f(0.0 + i, 10.0 + j);

    glVertex2f(0.0 + i, 15.0 + j);

    glVertex2f(600.0 + i, 15.0 + j);

    glVertex2f(600.0 + i, 10.0 + j);

    glEnd();

    glFlush();

}





void backk(int i , int j)

{





    glColor3f(0, .5, 1);

    glBegin(GL_QUADS);

    glVertex2f(0.0 + i, 0.0 + j);

    glVertex2f(600.0 + i, 0.0 + j);

    glVertex2f(600.0 + i, -500 + j);

    glVertex2f(0.0 + i, -500 + j);

    glEnd();

    glFlush();





}

void ground(int i , int j)

{



    glBegin(GL_QUADS);

    glColor3f(0, 1.0, 0);

    glVertex2f(0.0 + i, 0.0 + j);

    glVertex2f(600.0 + i, 0.0 + j);

    glVertex2f(600.0 + i, -j);

    glVertex2f(0.0 + i, -j);

    glEnd();

}











void egg()

{



    float x, y, z;

    int t;

    glColor3f(1.0, 10, 1.0);

    glBegin(GL_POLYGON);

    for (t = 0; t <= 360; t += 1)

    {

        x = egg_xc + 8 * (cos(t));

        y = egg_yc + 16 * (sin(t));

        z = 0;

        glVertex3f(x, y, z);

    }

    glEnd();

}

void basket(int i, int j)

{

    j = 10;

    if (i >= a - 60)i = a - 60;

    glColor3f(0.6, 0.3, 0);

    glBegin(GL_QUADS);

    glVertex2f(0.0 + i, 30.0 + j);

    glVertex2f(10.0 + i, 10.0 + j);

    glVertex2f(50.0 + i, 10.0 + j);

    glVertex2f(60.0 + i, 30.0 + j);

    glEnd();

}

void duck(int i, int j)

{

    int h;

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POLYGON);

    glVertex2f(45 + i, 45 + j);

    glVertex2f(70 + i, 20 + j);

    glVertex2f(95 + i, 20 + j);

    glVertex2f(120 + i, 45 + j);

    glVertex2f(95 + i, 70 + j);

    glVertex2f(70 + i, 70 + j);

    glVertex2f(95 + i, 95 + j);

    glVertex2f(82.5 + i, 107.5 + j);

    glVertex2f(32.5 + i, 57.5 + j);

    glEnd();

    glFlush();

    for (h = 0; h < 13; h += 4)

    {

        glBegin(GL_LINES);

        glColor3f(0.7, 0.4, 0);

        glVertex2f(57.5 + h + i, 52.5 + h + j);

        glVertex2f(100 + h + i, 30 + h + j);

        glEnd();

        glFlush();

    }

    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_POLYGON);

    glVertex2f(82.5 + i, 107.5 + j);

    glVertex2f(65 + i, 107.5 + j);

    glVertex2f(50 + i, 95 + j);

    glVertex2f(70 + i, 95 + j);

    glEnd();

    glFlush();

    glColor3f(0.0, 0.0, 0.0);

    glPointSize(5);

    glBegin(GL_POINTS);

    glVertex2f(76 + i, 101 + j);

    glEnd();

    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_LINE_LOOP);

    glVertex2f(72.5 + i, 107.5 + j);

    glVertex2f(67.5 + i, 112.5 + j);

    glVertex2f(72.5 + i, 110 + j);

    glVertex2f(77.5 + i, 112.5 + j);

    glEnd();

    glFlush();

}



void print_score()

{

    printf("\nLevel reached: %d\n\n", level_count);

    printf("\nNo. of eggs dropped= %d \n", dropped_eggs);

    printf("\nNo. of eggs caught = %d\n", eggs_caught);

    printf("\nNo. of eggs missed = %d\n", missed_eggs);



    getchar();

    exit(0);

}

void egg_start()

{

    egg_yc = 375;

    if (missed_eggs >= 10)

    {

        printf("\n\n\t\t\t\tGAME OVER\n\n");

        print_score();

    }

    dropped_eggs++;



    switch (rand() % 9)

    {

    case 0: egg_xc = 115; break;

    case 1: egg_xc = 255; break;

    case 2: egg_xc = 390; break;

    case 5: egg_xc = 115; break;

    case 3: egg_xc = 255; break;

    case 4: egg_xc = 390; break;

    case 7: egg_xc = 490; break;

    case 6: egg_xc = 255; break;

    case 8: egg_xc = 490; break;

    }

}









void score()

{

    if (egg_yc <= 50 && (egg_xc >= basket_x && egg_xc <= basket_x + 60))

    {

        printf("\a");

        eggs_caught++;

        egg_yc = -10;

    }

    missed_eggs = dropped_eggs - eggs_caught;

}

void display(void)

{

    glClear(GL_COLOR_BUFFER_BIT);

    ground(0 , 650);

    backk(0, 650);

    duck(40, 375);

    duck(180, 375);

    duck(320, 375);
    duck(425, 375);
    sun();

    cloud1();

    cloud2();

    cloud3();

    line(0, 375);



    int i;

    char z[12] = "";

    char level1[12] = "LEVEL 1";

    char level2[12] = "LEVEL 2";

    char level3[12] = "LEVEL 3";

    char level4[12] = "LEVEL 4";







    drawString(GLUT_BITMAP_TIMES_ROMAN_24, eggs_caught, 10, 560, 220);

    drawString1(GLUT_BITMAP_TIMES_ROMAN_24, "No of eggs caught:", 370, 220);

    drawString(GLUT_BITMAP_TIMES_ROMAN_24, missed_eggs - 1, 10, 560, 190);

    drawString1(GLUT_BITMAP_TIMES_ROMAN_24, "No of eggs missed:", 370, 190);


    if (s >= 1)

    {

        glColor3f(0, 0, 1);



        glRasterPos2i(10, 10);

        for (i = 0; i < 12; i++)

            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, z[i]);



        if (level_count == 1)

        {

            glColor3f(1, 1, 1);

            glRasterPos2i(500, 300);

            for (i = 0; i < 12; i++)

                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level1[i]);

        }

        else if (level_count == 2)

        {

            glColor3f(1, 0, 0);

            glRasterPos2i(500, 300);

            for (i = 0; i < 12; i++)

                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level2[i]);

        }

        else if (level_count == 3)

        {

            glColor3f(0, 1, 1);

            glRasterPos2i(500, 300);

            for (i = 0; i < 12; i++)

                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level3[i]);

        }

        if (level_count == 4)

        {

            glColor3f(1, 0, 1);

            glRasterPos2i(500, 300);

            for (i = 0; i < 12; i++)

                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, level4[i]);

        }



        if (egg_yc <= 10)

            egg_start();



        egg();

        basket(basket_x, basket_y);

        if (eggs_caught >= 10)

        {

            egg_yc -= speed_2;

            level_count = 2;

        }

        if (eggs_caught >= 20)

        {

            egg_yc -= speed_3;

            level_count = 3;

        }

        if (eggs_caught >= 30)

        {

            egg_yc -= speed_4;

            level_count = 4;

        }

        else

            egg_yc -= speed_1;

        score();

    }

    else

        start_screen(40, 300);

    glFlush();

    glutSwapBuffers();

}

void basket_set(int a, int b)

{

    basket_x = a;

    basket_y = b;

    glutPostRedisplay();

}

void myReshape(int w, int h)

{

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glViewport(0, 0, w, h);

    a = w;

    b = h;

}

void keys(unsigned char key, int x, int y)

{

    if (key == 'q' || key == 'Q')

    {

        printf("\n\n\n\t\tQUIT BY PLAYER\n\n");

        print_score();

    }

    if (key == 's' || key == 'S') s += 1;



    if (key == 'a' || key == 'A')

    {

        egg_xc -= 10;

        if (egg_xc <= 0) egg_xc = 10;

    }

    if (key == 'd' || key == 'D')

    {

        egg_xc += 10;

        if (egg_xc >= 500) egg_xc = 490;

    }



}

void menu(int id)

{

    switch (id)

    {

    case 1: s += 1;

        break;

    case 2: print_score();

        break;

    case 3: printf("\n\n\n\t\tQUIT BY PLAYER\n");

        break;

    default: exit(0);

    }

    glutPostRedisplay();

}

int main(int argc, char **argv)

{

    printf("********");

    printf("\n\t\t\t\t EGG GAME\n\n");

    printf("********");

    printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the eggs in the basket.\n\t To move Basket use mouse.\n");

    printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse button then click 'Start Game'.\n");

    printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right mouse button then click 'Quit'.\n");

    printf("\n\n RULES : If the player misses 10 eggs,then 'Game Over'.\n");

    printf("\nFor each level, speed is Increased\n\n");

    printf("\n\nBEST OF LUCK\n");



    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(a, b);

    glutCreateWindow("EGG GAME");

    myinit();

    glutInitWindowPosition (100, 100);

    glutCreateMenu(menu);

    glutAddMenuEntry("Start game", 1);

    glutAddMenuEntry("score", 2);

    glutAddMenuEntry("Quit", 3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);

    glutKeyboardFunc(keys);

    glutPassiveMotionFunc(basket_set);

    glutIdleFunc(display);

    glutReshapeFunc(myReshape);

    glutMainLoop();

}