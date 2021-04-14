#include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int a=0,a1 = 0;
int state=1;
static float i=0,j=0,k=0,l=1,m=-5,n=14;
double x = 0, z=0,xxx = 0, jjj=0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0;;
double posx = 0, posy = 0, posz = 2, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;


static int xangle=0,yangle=0,zangle=0;
//int state=1;
//static float j=0,k=0,l=1,m=-5,n=20,q=30,w=60,t=-5,e=-5,g=.1,s=0;
//double x = 0,xxx = 0, jjj=0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0;
static float xx=0,yy=0,zz=0;
static float xaxis=0,yaxis=0,zaxis=0;


static void idle(void)
{
    glutPostRedisplay();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/20,timer,0);

    switch(state)
    {
    case 1:
    {
        if(m<14 && n>-7)
        {
            if(l==1)
            {
                m+=0.15;
                n-=0.15;
            }

        }
        else
        {
            state=1;
            m=-5;
            n=14;

        }

        //break;


    }
    }

}


void special(int key, int, int)
{
    switch (key)
    {

        case GLUT_KEY_LEFT:
        z = (z - 0.1);
        if(z<-1)
        {
            z = 3.5;
        }
        break;
    case GLUT_KEY_RIGHT:
        z = (z + 0.1);
        if(z>3.5)
        {
            z = z-3.5;
        }
        break;

    case GLUT_KEY_F1:
        (a += 5) %= 100;
        break;
    case GLUT_KEY_F2:
        (a -= 5) %= -90;
        break;
    break;
    case GLUT_KEY_F10:
    {
        i=0,j=1,k=1,l=0;
    }
    break;
    case GLUT_KEY_F11:
    {
        i=0,j=0,k=0,l=1;
    }
    break;

    case GLUT_KEY_F4:
        posx += 0.5;
        break;
    case GLUT_KEY_F5:
        posx -= 0.5;
        break;
    case GLUT_KEY_F6:
        posy += 0.5;
        break;
    case GLUT_KEY_F7:
        posy -= 0.5;
        break;
    case GLUT_KEY_F8:
        posz += 0.5;
        break;
    case GLUT_KEY_F9:
        posz -= 0.5;
        break;
    default:
        return;
        /// Fpr circle
        /*glutSolidSphere(0.15,12,2);  //draw a sphere
        glFlush();*/

    }
    glutPostRedisplay();
}

void spin(int value)
{
    a1 = a1 - 5;
    if(a1 < -360)
    {
        a1 = a1 + 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, spin, 0);
}
void Monitor()
{

    ///Display Backside
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.30, -0.08,.21);
    glVertex3f (.30, -0.08, 0.21);
    glVertex3f (.30, 0.67, 0.21);
    glVertex3f (-.30, 0.67, 0.21);
    glEnd();
    ///Display top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.30, 0.67,0.25);
    glVertex3f (.30, 0.67, 0.25);
    glVertex3f (.30, 0.67, 0.21);
    glVertex3f (-.30, 0.67, 0.21);
    glEnd();

    ///Display left
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.30, -0.08,0.25);
    glVertex3f (-.30, 0.67, 0.25);
    glVertex3f (-.30, 0.67, 0.21);
    glVertex3f (-.30, -0.08, 0.21);
    glEnd();

    ///Display right
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.30, -0.08,0.25);
    glVertex3f (.30, 0.67, 0.25);
    glVertex3f (.30, 0.67, 0.21);
    glVertex3f (.30, -0.08, 0.21);
    glEnd();

    ///Display
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.30, -0.08,.25);
    glVertex3f (.30, -0.08, 0.25);
    glVertex3f (.30, 0.67, 0.25);
    glVertex3f (-.30, 0.67, 0.25);
    glEnd();

    ///Display round
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (-.28, 0.02,.25);
    glVertex3f (.28, 0.02, 0.25);
    glVertex3f (.28, 0.65, 0.25);
    glVertex3f (-.28, 0.65, 0.25);
    glEnd();


}

void Object()
{
    ///Front Book
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-.28, 0.02,.25);
    glVertex3f (.28, 0.02, 0.25);
    glVertex3f (.28, 0.03, 0.25);
    glVertex3f (-.28, 0.03, 0.25);
    glEnd();

}
void Laptop()
{

    ///keyboard bottom
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-.30, -0.10,.96);
    glVertex3f (.30, -0.10, 0.96);
    glVertex3f (.30, -0.10, 0.25);
    glVertex3f (-.30, -0.10, 0.25);
    glEnd();





     ///body right
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.30, -0.10,.96);
    glVertex3f (.30, -0.08, 0.96);
    glVertex3f (.30, -0.08,.25);
    glVertex3f (.30, -0.10,.25);

    glEnd();

    ///body left
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.30, -0.10,.96);
    glVertex3f (-.30, -0.08, 0.96);
    glVertex3f (-.30, -0.08,.25);
    glVertex3f (-.30, -0.10,.25);

    glEnd();

    ///keyboard
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-.30, -0.08,.96);
    glVertex3f (.30, -0.08, 0.96);
    glVertex3f (.30, -0.08, 0.25);
    glVertex3f (-.30, -0.08, 0.25);
    glEnd();


    ///body front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.30, -0.10,.96);
    glVertex3f (.30, -0.10, 0.96);
    glVertex3f (.30, -0.08, 0.96);
    glVertex3f (-.30, -0.08, 0.96);
    glEnd();

    ///keyboard row1 key1
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.25, -0.08,.36);
    glVertex3f (-.19, -0.08, 0.36);
    glVertex3f (-.19, -0.08, 0.30);
    glVertex3f (-.25, -0.08, 0.30);
    glEnd();

    ///keyboard row1 key2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.14, -0.08,.36);
    glVertex3f (-.08, -0.08, 0.36);
    glVertex3f (-.08, -0.08, 0.30);
    glVertex3f (-.14, -0.08, 0.30);
    glEnd();

    ///keyboard row1 key3
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.03, -0.08,.36);
    glVertex3f (.03, -0.08, 0.36);
    glVertex3f (.03, -0.08, 0.30);
    glVertex3f (-.03, -0.08, 0.30);
    glEnd();

    ///keyboard row1 key4
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.14, -0.08,.36);
    glVertex3f (.08, -0.08, 0.36);
    glVertex3f (.08, -0.08, 0.30);
    glVertex3f (.14, -0.08, 0.30);
    glEnd();


    ///keyboard row1 key5
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.25, -0.08,.36);
    glVertex3f (.19, -0.08, 0.36);
    glVertex3f (.19, -0.08, 0.30);
    glVertex3f (.25, -0.08, 0.30);
    glEnd();



    ///keyboard row2 key1
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.25, -0.08,.46);
    glVertex3f (-.19, -0.08, 0.46);
    glVertex3f (-.19, -0.08, 0.40);
    glVertex3f (-.25, -0.08, 0.40);
    glEnd();

    ///keyboard row2 key2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.14, -0.08,.46);
    glVertex3f (-.08, -0.08, 0.46);
    glVertex3f (-.08, -0.08, 0.40);
    glVertex3f (-.14, -0.08, 0.40);
    glEnd();

    ///keyboard row2 key3
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.03, -0.08, .46);
    glVertex3f (.03, -0.08, 0.46);
    glVertex3f (.03, -0.08, 0.40);
    glVertex3f (-.03, -0.08, 0.40);
    glEnd();

    ///keyboard row2 key4
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.14, -0.08, 0.46);
    glVertex3f (.08, -0.08, 0.46);
    glVertex3f (.08, -0.08, 0.40);
    glVertex3f (.14, -0.08, 0.40);
    glEnd();


    ///keyboard row2 key5
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.25, -0.08, 0.46);
    glVertex3f (.19, -0.08, 0.46);
    glVertex3f (.19, -0.08, 0.40);
    glVertex3f (.25, -0.08, 0.40);
    glEnd();


    ///keyboard row3 key1
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.25, -0.08,.56);
    glVertex3f (-.19, -0.08, 0.56);
    glVertex3f (-.19, -0.08, 0.50);
    glVertex3f (-.25, -0.08, 0.50);
    glEnd();

    ///keyboard row3 key2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.14, -0.08,.56);
    glVertex3f (-.08, -0.08, 0.56);
    glVertex3f (-.08, -0.08, 0.50);
    glVertex3f (-.14, -0.08, 0.50);
    glEnd();

    ///keyboard row3 key3
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.03, -0.08,.56);
    glVertex3f (.03, -0.08, 0.56);
    glVertex3f (.03, -0.08, 0.50);
    glVertex3f (-.03, -0.08, 0.50);
    glEnd();

    ///keyboard row3 key4
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.14, -0.08,.56);
    glVertex3f (.08, -0.08, 0.56);
    glVertex3f (.08, -0.08, 0.50);
    glVertex3f (.14, -0.08, 0.50);
    glEnd();


    ///keyboard row3 key5
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.25, -0.08,.56);
    glVertex3f (.19, -0.08, 0.56);
    glVertex3f (.19, -0.08, 0.50);
    glVertex3f (.25, -0.08, 0.50);
    glEnd();

    ///keyboard row4 key1
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.25, -0.08,.66);
    glVertex3f (-.19, -0.08, 0.66);
    glVertex3f (-.19, -0.08, 0.60);
    glVertex3f (-.25, -0.08, 0.60);
    glEnd();

    ///keyboard row4 key2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.14, -0.08,.66);
    glVertex3f (-.08, -0.08, 0.66);
    glVertex3f (-.08, -0.08, 0.60);
    glVertex3f (-.14, -0.08, 0.60);
    glEnd();

    ///keyboard row4 key3
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.03, -0.08,.66);
    glVertex3f (.03, -0.08, 0.66);
    glVertex3f (.03, -0.08, 0.60);
    glVertex3f (-.03, -0.08, 0.60);
    glEnd();

    ///keyboard row4 key4
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.14, -0.08,.66);
    glVertex3f (.08, -0.08, 0.66);
    glVertex3f (.08, -0.08, 0.60);
    glVertex3f (.14, -0.08, 0.60);
    glEnd();


    ///keyboard row4 key5
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.25, -0.08,.66);
    glVertex3f (.19, -0.08, 0.66);
    glVertex3f (.19, -0.08, 0.60);
    glVertex3f (.25, -0.08, 0.60);
    glEnd();

    ///keyboard row5 key1
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.25, -0.08,.76);
    glVertex3f (-.19, -0.08, 0.76);
    glVertex3f (-.19, -0.08, 0.70);
    glVertex3f (-.25, -0.08, 0.70);
    glEnd();

    ///keyboard row5 key2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.14, -0.08,.76);
    glVertex3f (-.08, -0.08, 0.76);
    glVertex3f (-.08, -0.08, 0.70);
    glVertex3f (-.14, -0.08, 0.70);
    glEnd();

    ///keyboard row5 key3
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.03, -0.08,.76);
    glVertex3f (.03, -0.08, 0.76);
    glVertex3f (.03, -0.08, 0.70);
    glVertex3f (-.03, -0.08, 0.70);
    glEnd();

    ///keyboard row5 key4
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.14, -0.08,.76);
    glVertex3f (.08, -0.08, 0.76);
    glVertex3f (.08, -0.08, 0.70);
    glVertex3f (.14, -0.08, 0.70);
    glEnd();


    ///keyboard row5 key5
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.25, -0.08,.76);
    glVertex3f (.19, -0.08, 0.76);
    glVertex3f (.19, -0.08, 0.70);
    glVertex3f (.25, -0.08, 0.70);
    glEnd();


    ///keyboard touchpad
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.08, -0.08,.88);
    glVertex3f (.08, -0.08, 0.88);
    glVertex3f (.08, -0.08, 0.80);
    glVertex3f (-.08, -0.08, 0.80);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.08, -0.08,.91);
    glVertex3f (-.005, -0.08, 0.91);
    glVertex3f (-.005, -0.08, 0.89);
    glVertex3f (-.08, -0.08, 0.89);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.08, -0.08,.91);
    glVertex3f (.005, -0.08, 0.91);
    glVertex3f (.005, -0.08, 0.89);
    glVertex3f (.08, -0.08, 0.89);
    glEnd();
}

void Table()
{

    ///Table Stand right back
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.42, -0.60, 0.16);
    glVertex3f (.42, -0.14, 0.16);
    glVertex3f (.42, -0.14, 0.10);
    glVertex3f (.42, -0.60, 0.10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.48, -0.60, 0.16);
    glVertex3f (.48, -0.14, 0.16);
    glVertex3f (.48, -0.14, 0.10);
    glVertex3f (.48, -0.60, 0.10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.48, -0.60, 0.16);
    glVertex3f (.42, -0.60, 0.16);
    glVertex3f (.42, -0.14, 0.16);
    glVertex3f (.48, -0.14, 0.16);
    glEnd();


    ///Table Stand left back
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (-.42, -0.60, 0.16);
    glVertex3f (-.42, -0.14, 0.16);
    glVertex3f (-.42, -0.14, 0.10);
    glVertex3f (-.42, -0.60, 0.10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (-.48, -0.60, 0.16);
    glVertex3f (-.48, -0.14, 0.16);
    glVertex3f (-.48, -0.14, 0.10);
    glVertex3f (-.48, -0.60, 0.10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.48, -0.60, 0.16);
    glVertex3f (-.42, -0.60, 0.16);
    glVertex3f (-.42, -0.14, 0.16);
    glVertex3f (-.48, -0.14, 0.16);
    glEnd();



    ///Table Stand left Front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (-.42, -0.60, 0.90);
    glVertex3f (-.42, -0.14, 0.90);
    glVertex3f (-.42, -0.14, 0.84);
    glVertex3f (-.42, -0.60, 0.84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (-.48, -0.60, 0.90);
    glVertex3f (-.48, -0.14, 0.90);
    glVertex3f (-.48, -0.14, 0.84);
    glVertex3f (-.48, -0.60, 0.84);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.48, -0.60, 0.90);
    glVertex3f (-.42, -0.60, 0.90);
    glVertex3f (-.42, -0.14, 0.90);
    glVertex3f (-.48, -0.14, 0.90);
    glEnd();


    ///Table Stand right Front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.42, -0.60, 0.90);
    glVertex3f (.42, -0.14, 0.90);
    glVertex3f (.42, -0.14, 0.84);
    glVertex3f (.42, -0.60, 0.84);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.48, -0.60, 0.90);
    glVertex3f (.48, -0.14, 0.90);
    glVertex3f (.48, -0.14, 0.84);
    glVertex3f (.48, -0.60, 0.84);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.48, -0.60, 0.90);
    glVertex3f (.42, -0.60, 0.90);
    glVertex3f (.42, -0.14, 0.90);
    glVertex3f (.48, -0.14, 0.90);
    glEnd();


    ///Table Box

    ///Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.42, -0.60, 0.90);
    glVertex3f (.42, -0.14, 0.90);
    glVertex3f (.42, -0.14, 0.78);
    glVertex3f (.42, -0.60, 0.78);
    glEnd();
    ///Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.30, -0.60, 0.90);
    glVertex3f (.30, -0.14, 0.90);
    glVertex3f (.30, -0.14, 0.78);
    glVertex3f (.30, -0.60, 0.78);
    glEnd();
    ///Front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);

    glVertex3f (.30, -0.60, 0.90);
    glVertex3f (.42, -0.60, 0.90);
    glVertex3f (.42, -0.14, 0.90);
    glVertex3f (.30, -0.14, 0.90);
    glEnd();

    ///Front round
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (.31, -0.59, 0.90);
    glVertex3f (.41, -0.59, 0.90);
    glVertex3f (.41, -0.15, 0.90);
    glVertex3f (.31, -0.15, 0.90);
    glEnd();

    ///Front row4
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.31, -0.45, 0.90);
    glVertex3f (.41, -0.45, 0.90);
    glVertex3f (.41, -0.44, 0.90);
    glVertex3f (.31, -0.44, 0.90);
    glEnd();



    ///Front row3
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.31, -0.37, 0.90);
    glVertex3f (.41, -0.37, 0.90);
    glVertex3f (.41, -0.36, 0.90);
    glVertex3f (.31, -0.36, 0.90);
    glEnd();

    ///Front row2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.31, -0.29, 0.90);
    glVertex3f (.41, -0.29, 0.90);
    glVertex3f (.41, -0.28, 0.90);
    glVertex3f (.31, -0.28, 0.90);
    glEnd();

    ///Front row1
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.31, -0.21, 0.90);
    glVertex3f (.41, -0.21, 0.90);
    glVertex3f (.41, -0.20, 0.90);
    glVertex3f (.31, -0.20, 0.90);
    glEnd();



    ///Table bottom
    glBegin(GL_QUADS);
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f (-.60, -0.14,1.0);
    glVertex3f (.60, -0.14, 1.0);
    glVertex3f (.60, -0.14, 0.0);
    glVertex3f (-.60, -0.14, 0.0);
    glEnd();


     ///Table Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f (-.60, -0.10,1.0);
    glVertex3f (.60, -0.10, 1.0);
    glVertex3f (.60, -0.10, 0.0);
    glVertex3f (-.60, -0.10, 0.0);
    glEnd();

     ///Table front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.60, -0.14, 1.0);
    glVertex3f (.60, -0.14, 1.0);
    glVertex3f (.60, -0.10, 1.0);
    glVertex3f (-.60, -0.10, 1.0);
    glEnd();



}
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'a': ///y axis down
    {
        yaxis = (yaxis - 0.1);
        if(yaxis<-5)
        {
            yaxis = 5;
        }
    }
    break;
    case 'b': ///y axis up
    {
        yaxis = (yaxis + 0.1);
        if(yaxis>5)
        {
            yaxis = -5;
        }
    }
    break;
    case 'c': ///z axis down
    {
        zaxis = (zaxis - 0.1);
        if(zaxis<-5)
        {
            zaxis = 5;
        }
    }
    break;
    case 'd':///z axis up
    {
        zaxis = (zaxis + 0.1);
        if(zaxis>5)
        {
            zaxis = -5;
        }
    }
    break;

    case 'x':///x axis rotation
    {
        (xangle -= 5) %= 360;
    }
    break;
    case 'm':///x axis another direction rotation
    {
        (xangle += 5) %= 360;
    }
    break;
    case 'y':///y axis rotation
    {
        (yangle -= 5) %= 360;
    }
    break;
    case 'n':///y axis another direction rotation
    {
        (yangle += 5) %= 360;
    }
    break;
    case 'z':///z axis rotation
    {
        (zangle -= 5) %= 360;
    }
    break;
    case 'o':///z axis rotation
    {
        (zangle += 5) %= 360;
    }
    break;

    case 'h':
        {
             xxx = (xxx - 0.2);
        if(xxx<-30)
        {
            xxx = xxx-.1;
        }
        }

    break;

    case 'j':
        {
             jjj = (jjj - 0.2);
        if(jjj<-30)
        {
            jjj = jjj-.1;
        }
        }

    break;

    case 'k':
        {
             jjj = (jjj + 0.2);
        if(jjj>30)
        {
            jjj = jjj-.1;
        }
        }

    break;



    case 'l':
        {
             xxx = (xxx + 0.2);
        if(xxx>30)
        {
            xxx= xxx-.1;
        }
        }
        break;


    default:
        break;
    }
    glutPostRedisplay();
}


void display()
{



    glClear(GL_COLOR_BUFFER_BIT);



    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Table();
    glPopMatrix();





    /*
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    glTranslatef(0,0,0+z);
    Monitor();
    glPopMatrix();
    */


    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    glScalef(.07+xx,.07+yy,.07+zz);
    Laptop();
    glPopMatrix();
    glPushMatrix();
    ///glTranslatef(0,0,0);
    glTranslatef(-0.30,-0.08,0.2);
    glRotatef((GLfloat)a,1,0,0);
    glTranslatef(0.30,0.08,-0.2);
    Monitor();
    glPopMatrix();
    /*///OBJECT_ANEMATION
    glPushMatrix();
    glTranslatef(0 ,-4+m, 0);
    glRotatef(0,0,0,0);
    glColor3f(0.419,0.556,0.137);
    Object();
    glPopMatrix();*/

    /*

    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(-31 ,-4, 5+ q);
    glRotatef(90.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car3();
    glPopMatrix();

*/





    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

    glutSwapBuffers();
}


void init()
{


    glClearColor (0.4, 0.85, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0/3.0, 1, 20);



}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Project");

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(25, spin, 0);
    glutTimerFunc(1000,timer,0);
    init();
    glutMainLoop();
}
