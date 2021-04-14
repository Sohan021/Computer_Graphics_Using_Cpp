#include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int a=0,a1 = 0,xangle=0,yangle=0,zangle=0;
int state=1;
static float i=0,j=0,k=0,l=1,m=-5,n=20,q=30,w=60,t=-5,e=-5,g=.1,s=0;
double x = 0,xxx = 0, jjj=0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0;
static float xx=0,yy=0,zz=0;
static float xaxis=0,yaxis=0,zaxis=0;
double posx = 0, posy = 0, posz = 2, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;
static void idle(void)
{
    glutPostRedisplay();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/15,timer,0);

    switch(state)
    {
    case 1:
    {
        if(m<20 && n>0 && q>-45 && w>10 && t<20 && e <20 && g>0 && s<100)
        {
            if(l==1)
            {
                m+=0.10;
                n-=0.15;
                q-=0.45;
                w-=0.30;
                s+=0.45;
                t+=0.12;
                e+=0.08;
                g-=0.0005;
            }

        }
        else
        {
            state=1;
            m=-5;
            n=20;
            q=25;
            w=60;
            s=0;
            t=-5;
            e=-5;
            g=.1;

        }
    }
    }

}


void special(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        x = (x - 0.1);
        if(x<-1)
        {
            x = 3.5;
        }
        break;
    case GLUT_KEY_RIGHT:
        x = (x + 0.1);
        if(x>3.5)
        {
            x = x-3.5;
        }
        break;

        case GLUT_KEY_UP:
        xx=xx+0.1;
        yy=yy+.1;
        zz=zz+0.1;
        if(xx>1 && yy>1 && zz>1)
        {
            xx=0;
            yy=0;
            zz=0;
        }
        break;
    case GLUT_KEY_DOWN:
        xx=xx-0.1;
        yy=yy-.1;
        zz=zz-0.1;
        if(xx<0 && yy<0 && zz<0)
        {
            xx=0;
            yy=0;
            zz=0;
        }
        break;
    case GLUT_KEY_F1:
        (a -= 5) %= 180;
        break;
    case GLUT_KEY_F2:
        (a += 5) %= 180;
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
    case GLUT_KEY_F3:
        ///ballMoveBack();
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

void Sun()
{
    glColor3f (1, .5, 0); //first cloud
    glPushMatrix();
    glTranslatef(0.9, 1.4, -.9);
    glutSolidSphere(0.2,36,100);
    glPopMatrix();
}

void cloud1()
{
    glColor3f (1, 1, 1); //first cloud
    glPushMatrix();
    glTranslatef(0.5, 1.8, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4, 1.75, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 1.8, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, 1.9, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.35, 1.88, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();


}

void cloud2()
{

     //second cloud
    glPushMatrix();
    glTranslatef(1.2, 1.8, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.3, 1.85, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25, 1.75, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.4, 1.8, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.35, 1.73, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();

}
void cloud3()
{
    glPushMatrix();
    glTranslatef(1.40, 1.8, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.50, 1.85, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.45, 1.75, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.60, 1.8, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.55, 1.73, 0);
    glutSolidSphere(0.1,36,100);
    glPopMatrix();

}

void Floor()
{


    ///Floor top backside
    glBegin(GL_QUADS);
    glColor3f (0.137255 , 0.556863,  0.137255);
    glVertex3f (-2.5, -0.3, -.30);
    glVertex3f (2.5, -0.3, -.30);
    glVertex3f (2.5, -0.3, -2.5);
    glVertex3f (-2.5,-0.3, -2.5);
    glEnd();


    ///Tree BackSide 1
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-2.0, -0.3, -2.4);
    glVertex3f (-1.96, -0.3, -2.4);
    glVertex3f (-1.96, 0.1, -2.4);
    glVertex3f (-2.0, 0.1, -2.4);
    glEnd();
    ///Tree Top 1
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-1.98, .1, -2.4);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-1.98, .25, -2.4);
    glutSolidSphere(0.09,36,100);
    glPopMatrix();


    ///Tree BackSide 2
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-1.50, -0.3, -2.4);
    glVertex3f (-1.46, -0.3, -2.4);
    glVertex3f (-1.46, 0.1, -2.4);
    glVertex3f (-1.50, 0.1, -2.4);
    glEnd();
    ///Tree Top 1
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-1.48, .2, -2.4);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-1.48, .35, -2.4);
    glutSolidSphere(0.09,36,100);
    glPopMatrix();

    ///Tree BackSide 3
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.90, -0.3, -2.4);
    glVertex3f (-0.86, -0.3, -2.4);
    glVertex3f (-0.86, 0.1, -2.4);
    glVertex3f (-0.90, 0.1, -2.4);
    glEnd();
    ///Tree Top 1
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.92, .2, -2.4);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.84, .2, -2.4);
    glutSolidSphere(0.09,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.88, .35, -2.4);
    glutSolidSphere(0.09,36,100);
    glPopMatrix();


     ///Tree BackSide 4
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (0.20, -0.3, -2.4);
    glVertex3f (0.24, -0.3, -2.4);
    glVertex3f (0.24, 0.1, -2.4);
    glVertex3f (0.20, 0.1, -2.4);
    glEnd();
    ///Tree Top 1
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(0.18, .2, -2.4);
    glutSolidSphere(0.12,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(.26, .2, -2.4);
    glutSolidSphere(0.12,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(.20, .35, -2.4);
    glutSolidSphere(0.09,36,100);
    glPopMatrix();


     ///Tree BackSide 4
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (2.36, -0.3, -2.4);
    glVertex3f (2.40, -0.3, -2.4);
    glVertex3f (2.40, 0.1, -2.4);
    glVertex3f (2.36, 0.1, -2.4);
    glEnd();
    ///Tree Top 1
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(2.38, .2, -2.4);
    glutSolidSphere(0.20,36,100);
    glPopMatrix();




    ///Floor top leftside
    glBegin(GL_QUADS);
    glColor3f (0.137255 , 0.556863,  0.137255);
    glVertex3f (-2.5, -0.3, 2.5);
    glVertex3f (-1.2, -0.3, 2.5);
    glVertex3f (-1.2, -0.3, -2.5);
    glVertex3f (-2.5, -0.3, -2.5);

    glEnd();

    ///Floor rightside
    glBegin(GL_QUADS);
    glColor3f (0.137255 , 0.556863,  0.137255);
    glVertex3f (-.70, -0.3, 2.5);
    glVertex3f (2.5, -0.3, 2.5);
    glVertex3f (2.5, -0.3, -2.5);
    glVertex3f (-.70, -0.3, -2.5);

    glEnd();

    ///Floor frontside
    glBegin(GL_QUADS);
    glColor3f (0.137255 , 0.556863,  0.137255);
    glVertex3f (-2.5, -0.3, 2.5);
    glVertex3f (2.5, -0.3, 2.5);
    glVertex3f (2.5, -0.3, .50);
    glVertex3f (-2.5, -0.3, .50);

    glEnd();



     ///Road Backside
    glBegin(GL_QUADS);
    glColor3f (0.0 , 0.0,  0.0);

    glVertex3f (-2.2, -0.3, -1.8);
    glVertex3f (2.2, -0.3, -1.8);
    glVertex3f (2.2, -0.3, -2.3);
    glVertex3f (-2.2,-0.3, -2.3);

    glEnd();

    ///Road Backside line 1
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.0, -0.3, -2.04);
    glVertex3f (-1.5, -0.3, -2.04);
    glVertex3f (-1.5, -0.3, -2.06);
    glVertex3f (-2.0, -0.3, -2.06);
    glEnd();

    ///Road Backside line 2
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-1.0, -0.3, -2.04);
    glVertex3f (-0.5, -0.3, -2.04);
    glVertex3f (-0.5, -0.3, -2.06);
    glVertex3f (-1.0, -0.3, -2.06);
    glEnd();

    ///Road Backside line 3
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (0.0, -0.3, -2.04);
    glVertex3f (0.5, -0.3, -2.04);
    glVertex3f (0.5, -0.3, -2.06);
    glVertex3f (0.0, -0.3, -2.06);
    glEnd();

    ///Road Backside line 4
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (1.0, -0.3, -2.04);
    glVertex3f (1.5, -0.3, -2.04);
    glVertex3f (1.5, -0.3, -2.06);
    glVertex3f (1.0, -0.3, -2.06);
    glEnd();

    ///Road frontside
    glBegin(GL_QUADS);
    glColor3f (0.0 , 0.0,  0.0);
    glVertex3f (-2.2, -0.3, 2.3);
    glVertex3f (2.2, -0.3, 2.3);
    glVertex3f (2.2, -0.3, 1.8);
    glVertex3f (-2.2, -0.3, 1.8);
    glEnd();


    ///Road frontside line 1
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.0, -0.3, 2.06);
    glVertex3f (-1.2, -0.3, 2.06);
    glVertex3f (-1.2, -0.3, 2.04);
    glVertex3f (-2.0, -0.3, 2.04);
    glEnd();

    ///Road frontside line 2
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-0.8, -0.3, 2.06);
    glVertex3f (-0.4, -0.3, 2.06);
    glVertex3f (-0.4, -0.3, 2.04);
    glVertex3f (-0.8, -0.3, 2.04);
    glEnd();

    ///Road frontside line 3
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-0.1, -0.3, 2.06);
    glVertex3f (0.3, -0.3, 2.06);
    glVertex3f (0.3, -0.3, 2.04);
    glVertex3f (-0.1, -0.3, 2.04);
    glEnd();

    ///Road frontside line 4
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (0.6, -0.3, 2.06);
    glVertex3f (1.1, -0.3, 2.06);
    glVertex3f (1.1, -0.3, 2.04);
    glVertex3f (0.6, -0.3, 2.04);
    glEnd();

     ///Road frontside line 5
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (1.4, -0.3, 2.06);
    glVertex3f (1.8, -0.3, 2.06);
    glVertex3f (1.8, -0.3, 2.04);
    glVertex3f (1.4, -0.3, 2.04);
    glEnd();

    ///Road top leftside
    glBegin(GL_QUADS);
    glColor3f (0.0 , 0.0,  0.0);
    glVertex3f (-2.3, -0.3, 2.3);
    glVertex3f (-1.8, -0.3, 2.3);
    glVertex3f (-1.8, -0.3, -2.3);
    glVertex3f (-2.3, -0.3, -2.3);
    glEnd();

    ///Road top leftside line 1
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, 2.2);
    glVertex3f (-2.04, -0.3, 2.2);
    glVertex3f (-2.04, -0.3, 1.9);
    glVertex3f (-2.06, -0.3, 1.9);
    glEnd();


    ///Road top leftside line 2
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, 1.6);
    glVertex3f (-2.04, -0.3, 1.6);
    glVertex3f (-2.04, -0.3, 1.2);
    glVertex3f (-2.06, -0.3, 1.2);
    glEnd();

     ///Road top leftside line 3
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, 0.9);
    glVertex3f (-2.04, -0.3, 0.9);
    glVertex3f (-2.04, -0.3, 0.5);
    glVertex3f (-2.06, -0.3, 0.5);
    glEnd();


    ///Road top leftside line 4
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, 0.3);
    glVertex3f (-2.04, -0.3, 0.3);
    glVertex3f (-2.04, -0.3, 0.1);
    glVertex3f (-2.06, -0.3, 0.1);
    glEnd();

    ///Road top leftside line 5
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, -0.9);
    glVertex3f (-2.04, -0.3, -0.9);
    glVertex3f (-2.04, -0.3, -0.6);
    glVertex3f (-2.06, -0.3, -0.6);
    glEnd();

    ///Road top leftside line 6
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, -1.3);
    glVertex3f (-2.04, -0.3, -1.3);
    glVertex3f (-2.04, -0.3, -1.6);
    glVertex3f (-2.06, -0.3, -1.6);
    glEnd();

     ///Road top leftside line 7
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, -0.3);
    glVertex3f (-2.04, -0.3, -0.3);
    glVertex3f (-2.04, -0.3, 0.0);
    glVertex3f (-2.06, -0.3, 0.0);
    glEnd();

    ///Road top leftside line 7
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (-2.06, -0.3, -1.9);
    glVertex3f (-2.04, -0.3, -1.9);
    glVertex3f (-2.04, -0.3, -2.2);
    glVertex3f (-2.06, -0.3, -2.2);
    glEnd();

    ///Right rightside
    glBegin(GL_QUADS);
    glColor3f (0.0 , 0.0,  0.0);
    glVertex3f (1.8, -0.3, 2.2);
    glVertex3f (2.2, -0.3, 2.2);
    glVertex3f (2.2, -0.3, -2.2);
    glVertex3f (1.8, -0.3, -2.2);

    glEnd();

      ///Road top rightside line 1
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, 2.2);
    glVertex3f (2.04, -0.3, 2.2);
    glVertex3f (2.04, -0.3, 1.9);
    glVertex3f (2.06, -0.3, 1.9);
    glEnd();


    ///Road top rightside line 2
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, 1.6);
    glVertex3f (2.04, -0.3, 1.6);
    glVertex3f (2.04, -0.3, 1.2);
    glVertex3f (2.06, -0.3, 1.2);
    glEnd();

     ///Road top rightside line 3
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, 0.9);
    glVertex3f (2.04, -0.3, 0.9);
    glVertex3f (2.04, -0.3, 0.5);
    glVertex3f (2.06, -0.3, 0.5);
    glEnd();


    ///Road top rightside line 4
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, 0.3);
    glVertex3f (2.04, -0.3, 0.3);
    glVertex3f (2.04, -0.3, 0.1);
    glVertex3f (2.06, -0.3, 0.1);
    glEnd();

    ///Road top rightside line 5
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, -0.9);
    glVertex3f (2.04, -0.3, -0.9);
    glVertex3f (2.04, -0.3, -0.6);
    glVertex3f (2.06, -0.3, -0.6);
    glEnd();

    ///Road top rightside line 6
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, -1.3);
    glVertex3f (2.04, -0.3, -1.3);
    glVertex3f (2.04, -0.3, -1.6);
    glVertex3f (2.06, -0.3, -1.6);
    glEnd();

     ///Road top rightside line 7
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, -0.3);
    glVertex3f (2.04, -0.3, -0.3);
    glVertex3f (2.04, -0.3, 0.0);
    glVertex3f (2.06, -0.3, 0.0);
    glEnd();

    ///Road top rightside line 7
    glBegin(GL_QUADS);
    glColor3f (1.0 , 1.0,  1.0);
    glVertex3f (2.06, -0.3, -1.9);
    glVertex3f (2.04, -0.3, -1.9);
    glVertex3f (2.04, -0.3, -2.2);
    glVertex3f (2.06, -0.3, -2.2);
    glEnd();



}

void BoundaryFront()
{
    ///Boundry Botton
     glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.3, 1.50);
    glVertex3f (1.5, -0.3, 1.50);
    glVertex3f (1.5, -0.3, 1.48);
    glVertex3f (-1.50, -0.3, 1.48);
    glEnd();
    ///Boundry 17....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.28, -0.30, 1.50);
    glVertex3f (-1.28, -0.10, 1.50);
    glVertex3f (-1.28, -0.10, 1.48);
    glVertex3f (-1.28, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.30, -0.30, 1.50);
    glVertex3f (-1.30, -0.10, 1.50);
    glVertex3f (-1.30, -0.10, 1.48);
    glVertex3f (-1.30, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.30, -0.30, 1.50);
    glVertex3f (-1.28, -0.30, 1.50);
    glVertex3f (-1.28, -0.10, 1.50);
    glVertex3f (-1.30, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.30, -0.10, 1.50);
    glVertex3f (-1.28, -0.10, 1.50);
    glVertex3f (-1.28, -0.10, 1.48);
    glVertex3f (-1.30, -0.10, 1.48);
    glEnd();


    ///Boundry 18....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.08, -0.30, 1.50);
    glVertex3f (-1.08, -0.10, 1.50);
    glVertex3f (-1.08, -0.10, 1.48);
    glVertex3f (-1.08, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.10, -0.30, 1.50);
    glVertex3f (-1.10, -0.10, 1.50);
    glVertex3f (-1.10, -0.10, 1.48);
    glVertex3f (-1.10, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.10, -0.30, 1.50);
    glVertex3f (-1.08, -0.30, 1.50);
    glVertex3f (-1.08, -0.10, 1.50);
    glVertex3f (-1.10, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.10, -0.10, 1.50);
    glVertex3f (-1.08, -0.10, 1.50);
    glVertex3f (-1.08, -0.10, 1.48);
    glVertex3f (-1.10, -0.10, 1.48);
    glEnd();

    ///Boundry 19....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.88, -0.30, 1.50);
    glVertex3f (-0.88, -0.10, 1.50);
    glVertex3f (-0.88, -0.10, 1.48);
    glVertex3f (-0.88, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.90, -0.30, 1.50);
    glVertex3f (-0.90, -0.10, 1.50);
    glVertex3f (-0.90, -0.10, 1.48);
    glVertex3f (-0.90, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.90, -0.30, 1.50);
    glVertex3f (-0.88, -0.30, 1.50);
    glVertex3f (-0.88, -0.10, 1.50);
    glVertex3f (-0.90, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.90, -0.10, 1.50);
    glVertex3f (-0.88, -0.10, 1.50);
    glVertex3f (-0.88, -0.10, 1.48);
    glVertex3f (-0.90, -0.10, 1.48);
    glEnd();


    ///Boundry 20....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.68, -0.30, 1.50);
    glVertex3f (-0.68, -0.10, 1.50);
    glVertex3f (-0.68, -0.10, 1.48);
    glVertex3f (-0.68, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.70, -0.30, 1.50);
    glVertex3f (-0.70, -0.10, 1.50);
    glVertex3f (-0.70, -0.10, 1.48);
    glVertex3f (-0.70, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.70, -0.30, 1.50);
    glVertex3f (-0.68, -0.30, 1.50);
    glVertex3f (-0.68, -0.10, 1.50);
    glVertex3f (-0.70, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.70, -0.10, 1.50);
    glVertex3f (-0.68, -0.10, 1.50);
    glVertex3f (-0.68, -0.10, 1.48);
    glVertex3f (-0.70, -0.10, 1.48);
    glEnd();


    ///Boundry 21....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.48, -0.30, 1.50);
    glVertex3f (-0.48, -0.10, 1.50);
    glVertex3f (-0.48, -0.10, 1.48);
    glVertex3f (-0.48, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.50, -0.30, 1.50);
    glVertex3f (-0.50, -0.10, 1.50);
    glVertex3f (-0.50, -0.10, 1.48);
    glVertex3f (-0.50, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.50, -0.30, 1.50);
    glVertex3f (-0.48, -0.30, 1.50);
    glVertex3f (-0.48, -0.10, 1.50);
    glVertex3f (-0.50, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.50, -0.10, 1.50);
    glVertex3f (-0.48, -0.10, 1.50);
    glVertex3f (-0.48, -0.10, 1.48);
    glVertex3f (-0.50, -0.10, 1.48);
    glEnd();


    ///Boundry 22....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.48, -0.30, 1.50);
    glVertex3f (0.48, -0.10, 1.50);
    glVertex3f (0.48, -0.10, 1.48);
    glVertex3f (0.48, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.50, -0.30, 1.50);
    glVertex3f (0.50, -0.10, 1.50);
    glVertex3f (0.50, -0.10, 1.48);
    glVertex3f (0.50, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.50, -0.30, 1.50);
    glVertex3f (0.48, -0.30, 1.50);
    glVertex3f (0.48, -0.10, 1.50);
    glVertex3f (0.50, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.50, -0.10, 1.50);
    glVertex3f (0.48, -0.10, 1.50);
    glVertex3f (0.48, -0.10, 1.48);
    glVertex3f (0.50, -0.10, 1.48);
    glEnd();


    ///Boundry 23....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.68, -0.30, 1.50);
    glVertex3f (0.68, -0.10, 1.50);
    glVertex3f (0.68, -0.10, 1.48);
    glVertex3f (0.68, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.70, -0.30, 1.50);
    glVertex3f (0.70, -0.10, 1.50);
    glVertex3f (0.70, -0.10, 1.48);
    glVertex3f (0.70, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.70, -0.30, 1.50);
    glVertex3f (0.68, -0.30, 1.50);
    glVertex3f (0.68, -0.10, 1.50);
    glVertex3f (0.70, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.70, -0.10, 1.50);
    glVertex3f (0.68, -0.10, 1.50);
    glVertex3f (0.68, -0.10, 1.48);
    glVertex3f (0.70, -0.10, 1.48);
    glEnd();

    ///Boundry 20....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.88, -0.30, 1.50);
    glVertex3f (0.88, -0.10, 1.50);
    glVertex3f (0.88, -0.10, 1.48);
    glVertex3f (0.88, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.90, -0.30, 1.50);
    glVertex3f (0.90, -0.10, 1.50);
    glVertex3f (0.90, -0.10, 1.48);
    glVertex3f (0.90, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.90, -0.30, 1.50);
    glVertex3f (0.88, -0.30, 1.50);
    glVertex3f (0.88, -0.10, 1.50);
    glVertex3f (0.90, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.90, -0.10, 1.50);
    glVertex3f (0.88, -0.10, 1.50);
    glVertex3f (0.88, -0.10, 1.48);
    glVertex3f (0.90, -0.10, 1.48);
    glEnd();



    ///Boundry 18....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.08, -0.30, 1.50);
    glVertex3f (1.08, -0.10, 1.50);
    glVertex3f (1.08, -0.10, 1.48);
    glVertex3f (1.08, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.10, -0.30, 1.50);
    glVertex3f (1.10, -0.10, 1.50);
    glVertex3f (1.10, -0.10, 1.48);
    glVertex3f (1.10, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.10, -0.30, 1.50);
    glVertex3f (1.08, -0.30, 1.50);
    glVertex3f (1.08, -0.10, 1.50);
    glVertex3f (1.10, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.10, -0.10, 1.50);
    glVertex3f (1.08, -0.10, 1.50);
    glVertex3f (1.08, -0.10, 1.48);
    glVertex3f (1.10, -0.10, 1.48);
    glEnd();

    ///Boundry 17....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.28, -0.30, 1.50);
    glVertex3f (1.28, -0.10, 1.50);
    glVertex3f (1.28, -0.10, 1.48);
    glVertex3f (1.28, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.30, -0.30, 1.50);
    glVertex3f (1.30, -0.10, 1.50);
    glVertex3f (1.30, -0.10, 1.48);
    glVertex3f (1.30, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.30, -0.30, 1.50);
    glVertex3f (1.28, -0.30, 1.50);
    glVertex3f (1.28, -0.10, 1.50);
    glVertex3f (1.30, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.30, -0.10, 1.50);
    glVertex3f (1.28, -0.10, 1.50);
    glVertex3f (1.28, -0.10, 1.48);
    glVertex3f (1.30, -0.10, 1.48);
    glEnd();

    ///Boundry 18....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 1.50);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.48, -0.10, 1.48);
    glVertex3f (1.48, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.50);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (1.50, -0.10, 1.48);
    glVertex3f (1.50, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.50);
    glVertex3f (1.48, -0.30, 1.50);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.50, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.48, -0.10, 1.48);
    glVertex3f (1.50, -0.10, 1.48);
    glEnd();





    ///Gate Left 1....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.30, -0.30, 1.50);
    glVertex3f (-0.30, 0.10, 1.50);
    glVertex3f (-0.30, 0.10, 1.48);
    glVertex3f (-0.30, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.28, -0.30, 1.50);
    glVertex3f (-0.28, 0.10, 1.50);
    glVertex3f (-0.28, 0.10, 1.48);
    glVertex3f (-0.28, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (0.137255, 0.137255, 0.556863);
    glVertex3f (-0.30, -0.30, 1.50);
    glVertex3f (-0.28, -0.30, 1.50);
    glVertex3f (-0.28, 0.10, 1.50);
    glVertex3f (-0.30,  0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.30, 0.10, 1.50);
    glVertex3f (-0.28, 0.10, 1.50);
    glVertex3f (-0.28, 0.10, 1.48);
    glVertex3f (-0.30, 0.10, 1.48);
    glEnd();


    ///Gate Left 2....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.26, -0.30, 1.50);
    glVertex3f (-0.26, 0.10, 1.50);
    glVertex3f (-0.26, 0.10, 1.48);
    glVertex3f (-0.26, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.24, -0.30, 1.50);
    glVertex3f (-0.24, 0.10, 1.50);
    glVertex3f (-0.24, 0.10, 1.48);
    glVertex3f (-0.24, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (0.137255, 0.137255, 0.556863);
    glVertex3f (-0.26, -0.30, 1.50);
    glVertex3f (-0.24, -0.30, 1.50);
    glVertex3f (-0.24, 0.10, 1.50);
    glVertex3f (-0.26,  0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.26, 0.10, 1.50);
    glVertex3f (-0.24, 0.10, 1.50);
    glVertex3f (-0.24, 0.10, 1.48);
    glVertex3f (-0.26, 0.10, 1.48);
    glEnd();


    ///Gate Right 2....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.26, -0.30, 1.50);
    glVertex3f (0.26, 0.10, 1.50);
    glVertex3f (0.26, 0.10, 1.48);
    glVertex3f (0.26, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.24, -0.30, 1.50);
    glVertex3f (0.24, 0.10, 1.50);
    glVertex3f (0.24, 0.10, 1.48);
    glVertex3f (0.24, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (0.137255, 0.137255, 0.556863);
    glVertex3f (0.26, -0.30, 1.50);
    glVertex3f (0.24, -0.30, 1.50);
    glVertex3f (0.24, 0.10, 1.50);
    glVertex3f (0.26,  0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.26, 0.10, 1.50);
    glVertex3f (0.24, 0.10, 1.50);
    glVertex3f (0.24, 0.10, 1.48);
    glVertex3f (0.26, 0.10, 1.48);
    glEnd();

    ///Gate Right 1....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.30, -0.30, 1.50);
    glVertex3f (0.30, 0.10, 1.50);
    glVertex3f (0.30, 0.10, 1.48);
    glVertex3f (0.30, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.28, -0.30, 1.50);
    glVertex3f (0.28, 0.10, 1.50);
    glVertex3f (0.28, 0.10, 1.48);
    glVertex3f (0.28, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (0.137255, 0.137255, 0.556863);
    glVertex3f (0.30, -0.30, 1.50);
    glVertex3f (0.28, -0.30, 1.50);
    glVertex3f (0.28, 0.10, 1.50);
    glVertex3f (0.30,  0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.30, 0.10, 1.50);
    glVertex3f (0.28, 0.10, 1.50);
    glVertex3f (0.28, 0.10, 1.48);
    glVertex3f (0.30, 0.10, 1.48);
    glEnd();

    ///Gate Top 1

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.32, 0.07, 1.50);
    glVertex3f (0.32, 0.09, 1.50);
    glVertex3f (0.32, 0.09, 1.48);
    glVertex3f (0.32, 0.07, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.32, 0.07, 1.50);
    glVertex3f (-0.32, 0.09, 1.50);
    glVertex3f (-0.32, 0.09, 1.48);
    glVertex3f (-0.32, 0.07, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (0.137255, 0.137255, 0.556863);
    glVertex3f (0.32, 0.07, 1.50);
    glVertex3f (-0.32, 0.07, 1.50);
    glVertex3f (-0.32, 0.09, 1.50);
    glVertex3f (0.32, 0.09, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.32, 0.07, 1.50);
    glVertex3f (-0.3, 0.07, 1.50);
    glVertex3f (-0.28, 0.07, 1.48);
    glVertex3f (-0.30, 0.07, 1.48);
    glEnd();

    ///Gate Top 2

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.32, 0.04, 1.50);
    glVertex3f (0.32, 0.06, 1.50);
    glVertex3f (0.32, 0.06, 1.48);
    glVertex3f (0.32, 0.04, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.32, 0.04, 1.50);
    glVertex3f (-0.32, 0.06, 1.50);
    glVertex3f (-0.32, 0.06, 1.48);
    glVertex3f (-0.32, 0.04, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (0.137255, 0.137255, 0.556863);
    glVertex3f (0.32, 0.04, 1.50);
    glVertex3f (-0.32, 0.04, 1.50);
    glVertex3f (-0.32, 0.06, 1.50);
    glVertex3f (0.32, 0.06, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.32, 0.04, 1.50);
    glVertex3f (-0.3, 0.04, 1.50);
    glVertex3f (-0.28, 0.04, 1.48);
    glVertex3f (-0.30, 0.04, 1.48);
    glEnd();

    ///Boundary Top
    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.10, 1.50);
    glVertex3f (-.30, -0.10, 1.50);
    glVertex3f (-.30, -0.12, 1.48);
    glVertex3f (-1.50, -0.12, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.50);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (1.50, -0.10, 1.48);
    glVertex3f (1.50, -0.30, 1.48);
    glEnd();
    ///Left
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.10, 1.50);
    glVertex3f (-.30, -0.10, 1.50);
    glVertex3f (-.30, -0.08, 1.48);
    glVertex3f (-1.50, -0.08, 1.48);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.08, 1.50);
    glVertex3f (-0.30, -0.08, 1.50);
    glVertex3f (-0.30, -0.08, 1.48);
    glVertex3f (-1.50, -0.08, 1.48);
    glEnd();

    ///Right
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (.30, -0.10, 1.50);
    glVertex3f (.30, -0.08, 1.48);
    glVertex3f (1.50, -0.08, 1.48);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.08, 1.50);
    glVertex3f (0.30, -0.08, 1.50);
    glVertex3f (0.30, -0.08, 1.48);
    glVertex3f (1.50, -0.08, 1.48);
    glEnd();




}

void BoundaryBack()
{


    ///Boundry buttom
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.3, -1.50);
    glVertex3f (1.50, -0.3, -1.50);
    glVertex3f (1.50, -0.3, -1.48);
    glVertex3f (-1.50, -0.3, -1.48);
    glEnd();
    ///Boundry 1....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.28, -0.30, -1.50);
    glVertex3f (-1.28, -0.10, -1.50);
    glVertex3f (-1.28, -0.10, -1.48);
    glVertex3f (-1.28, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.30, -0.30, -1.50);
    glVertex3f (-1.30, -0.10, -1.50);
    glVertex3f (-1.30, -0.10, -1.48);
    glVertex3f (-1.30, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.30, -0.30, -1.50);
    glVertex3f (-1.28, -0.30, -1.50);
    glVertex3f (-1.28, -0.10, -1.50);
    glVertex3f (-1.30, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.30, -0.10, -1.50);
    glVertex3f (-1.28, -0.10, -1.50);
    glVertex3f (-1.28, -0.10, -1.48);
    glVertex3f (-1.30, -0.10, -1.48);
    glEnd();


    ///Boundry 2....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.08, -0.30, -1.50);
    glVertex3f (-1.08, -0.10, -1.50);
    glVertex3f (-1.08, -0.10, -1.48);
    glVertex3f (-1.08, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.10, -0.30, -1.50);
    glVertex3f (-1.10, -0.10, -1.50);
    glVertex3f (-1.10, -0.10, -1.48);
    glVertex3f (-1.10, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.10, -0.30, -1.50);
    glVertex3f (-1.08, -0.30, -1.50);
    glVertex3f (-1.08, -0.10, -1.50);
    glVertex3f (-1.10, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.10, -0.10, -1.50);
    glVertex3f (-1.08, -0.10, -1.50);
    glVertex3f (-1.08, -0.10, -1.48);
    glVertex3f (-1.10, -0.10, -1.48);
    glEnd();

    ///Boundry 3....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.88, -0.30, -1.50);
    glVertex3f (-0.88, -0.10, -1.50);
    glVertex3f (-0.88, -0.10, -1.48);
    glVertex3f (-0.88, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.90, -0.30, -1.50);
    glVertex3f (-0.90, -0.10, -1.50);
    glVertex3f (-0.90, -0.10, -1.48);
    glVertex3f (-0.90, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.90, -0.30, -1.50);
    glVertex3f (-0.88, -0.30, -1.50);
    glVertex3f (-0.88, -0.10, -1.50);
    glVertex3f (-0.90, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.90, -0.10, -1.50);
    glVertex3f (-0.88, -0.10, -1.50);
    glVertex3f (-0.88, -0.10, -1.48);
    glVertex3f (-0.90, -0.10, -1.48);
    glEnd();


    ///Boundry 4....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.68, -0.30, -1.50);
    glVertex3f (-0.68, -0.10, -1.50);
    glVertex3f (-0.68, -0.10, -1.48);
    glVertex3f (-0.68, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.70, -0.30, -1.50);
    glVertex3f (-0.70, -0.10, -1.50);
    glVertex3f (-0.70, -0.10, -1.48);
    glVertex3f (-0.70, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.70, -0.30, -1.50);
    glVertex3f (-0.68, -0.30, -1.50);
    glVertex3f (-0.68, -0.10, -1.50);
    glVertex3f (-0.70, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.70, -0.10, -1.50);
    glVertex3f (-0.68, -0.10, -1.50);
    glVertex3f (-0.68, -0.10, -1.48);
    glVertex3f (-0.70, -0.10, -1.48);
    glEnd();


    ///Boundry 5....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.48, -0.30, -1.50);
    glVertex3f (-0.48, -0.10, -1.50);
    glVertex3f (-0.48, -0.10, -1.48);
    glVertex3f (-0.48, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.50, -0.30, -1.50);
    glVertex3f (-0.50, -0.10, -1.50);
    glVertex3f (-0.50, -0.10, -1.48);
    glVertex3f (-0.50, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.50, -0.30, -1.50);
    glVertex3f (-0.48, -0.30, -1.50);
    glVertex3f (-0.48, -0.10, -1.50);
    glVertex3f (-0.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.50, -0.10, -1.50);
    glVertex3f (-0.48, -0.10, -1.50);
    glVertex3f (-0.48, -0.10, -1.48);
    glVertex3f (-0.50, -0.10, -1.48);
    glEnd();


    ///Boundry 6....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.28, -0.30, -1.50);
    glVertex3f (-0.28, -0.10, -1.50);
    glVertex3f (-0.28, -0.10, -1.48);
    glVertex3f (-0.28, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.30, -0.30, -1.50);
    glVertex3f (-0.30, -0.10, -1.50);
    glVertex3f (-0.30, -0.10, -1.48);
    glVertex3f (-0.30, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.30, -0.30, -1.50);
    glVertex3f (-0.28, -0.30, -1.50);
    glVertex3f (-0.28, -0.10, -1.50);
    glVertex3f (-0.30, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.30, -0.10, -1.50);
    glVertex3f (-0.28, -0.10, -1.50);
    glVertex3f (-0.28, -0.10, -1.48);
    glVertex3f (-0.30, -0.10, -1.48);
    glEnd();

    ///Boundry 7....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.08, -0.30, -1.50);
    glVertex3f (-0.08, -0.10, -1.50);
    glVertex3f (-0.08, -0.10, -1.48);
    glVertex3f (-0.08, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.10, -0.30, -1.50);
    glVertex3f (-0.10, -0.10, -1.50);
    glVertex3f (-0.10, -0.10, -1.48);
    glVertex3f (-0.10, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.10, -0.30, -1.50);
    glVertex3f (-0.08, -0.30, -1.50);
    glVertex3f (-0.08, -0.10, -1.50);
    glVertex3f (-0.10, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-0.10, -0.10, -1.50);
    glVertex3f (-0.08, -0.10, -1.50);
    glVertex3f (-0.08, -0.10, -1.48);
    glVertex3f (-0.10, -0.10, -1.48);
    glEnd();

    ///Boundry 8....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.08, -0.30, -1.50);
    glVertex3f (0.08, -0.10, -1.50);
    glVertex3f (0.08, -0.10, -1.48);
    glVertex3f (0.08, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.10, -0.30, -1.50);
    glVertex3f (0.10, -0.10, -1.50);
    glVertex3f (0.10, -0.10, -1.48);
    glVertex3f (0.10, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.10, -0.30, -1.50);
    glVertex3f (0.08, -0.30, -1.50);
    glVertex3f (0.08, -0.10, -1.50);
    glVertex3f (0.10, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.10, -0.10, -1.50);
    glVertex3f (0.08, -0.10, -1.50);
    glVertex3f (0.08, -0.10, -1.48);
    glVertex3f (0.10, -0.10, -1.48);
    glEnd();


    ///Boundry 9....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.28, -0.30, -1.50);
    glVertex3f (0.28, -0.10, -1.50);
    glVertex3f (0.28, -0.10, -1.48);
    glVertex3f (0.28, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.30, -0.30, -1.50);
    glVertex3f (0.30, -0.10, -1.50);
    glVertex3f (0.30, -0.10, -1.48);
    glVertex3f (0.30, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.30, -0.30, -1.50);
    glVertex3f (0.28, -0.30, -1.50);
    glVertex3f (0.28, -0.10, -1.50);
    glVertex3f (0.30, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.30, -0.10, -1.50);
    glVertex3f (0.28, -0.10, -1.50);
    glVertex3f (0.28, -0.10, -1.48);
    glVertex3f (0.30, -0.10, -1.48);
    glEnd();




    ///Boundry 10....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.48, -0.30, -1.50);
    glVertex3f (0.48, -0.10, -1.50);
    glVertex3f (0.48, -0.10, -1.48);
    glVertex3f (0.48, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.50, -0.30, -1.50);
    glVertex3f (0.50, -0.10, -1.50);
    glVertex3f (0.50, -0.10, -1.48);
    glVertex3f (0.50, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.50, -0.30, -1.50);
    glVertex3f (0.48, -0.30, -1.50);
    glVertex3f (0.48, -0.10, -1.50);
    glVertex3f (0.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.50, -0.10, -1.50);
    glVertex3f (0.48, -0.10, -1.50);
    glVertex3f (0.48, -0.10, -1.48);
    glVertex3f (0.50, -0.10, -1.48);
    glEnd();


    ///Boundry 11....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.68, -0.30, -1.50);
    glVertex3f (0.68, -0.10, -1.50);
    glVertex3f (0.68, -0.10, -1.48);
    glVertex3f (0.68, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.70, -0.30, -1.50);
    glVertex3f (0.70, -0.10, -1.50);
    glVertex3f (0.70, -0.10, -1.48);
    glVertex3f (0.70, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.70, -0.30, -1.50);
    glVertex3f (0.68, -0.30, -1.50);
    glVertex3f (0.68, -0.10, -1.50);
    glVertex3f (0.70, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.70, -0.10, -1.50);
    glVertex3f (0.68, -0.10, -1.50);
    glVertex3f (0.68, -0.10, -1.48);
    glVertex3f (0.70, -0.10, -1.48);
    glEnd();

    ///Boundry 12....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.88, -0.30, -1.50);
    glVertex3f (0.88, -0.10, -1.50);
    glVertex3f (0.88, -0.10, -1.48);
    glVertex3f (0.88, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.90, -0.30, -1.50);
    glVertex3f (0.90, -0.10, -1.50);
    glVertex3f (0.90, -0.10, -1.48);
    glVertex3f (0.90, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.90, -0.30, -1.50);
    glVertex3f (0.88, -0.30, -1.50);
    glVertex3f (0.88, -0.10, -1.50);
    glVertex3f (0.90, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.90, -0.10, -1.50);
    glVertex3f (0.88, -0.10, -1.50);
    glVertex3f (0.88, -0.10, -1.48);
    glVertex3f (0.90, -0.10, -1.48);
    glEnd();



    ///Boundry 13....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.08, -0.30, -1.50);
    glVertex3f (1.08, -0.10, -1.50);
    glVertex3f (1.08, -0.10, -1.48);
    glVertex3f (1.08, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.10, -0.30, -1.50);
    glVertex3f (1.10, -0.10, -1.50);
    glVertex3f (1.10, -0.10, -1.48);
    glVertex3f (1.10, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.10, -0.30, -1.50);
    glVertex3f (1.08, -0.30, -1.50);
    glVertex3f (1.08, -0.10, -1.50);
    glVertex3f (1.10, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.10, -0.10, -1.50);
    glVertex3f (1.08, -0.10, -1.50);
    glVertex3f (1.08, -0.10, -1.48);
    glVertex3f (1.10, -0.10, -1.48);
    glEnd();

    ///Boundry 14....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.28, -0.30, -1.50);
    glVertex3f (1.28, -0.10, -1.50);
    glVertex3f (1.28, -0.10, -1.48);
    glVertex3f (1.28, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.30, -0.30, -1.50);
    glVertex3f (1.30, -0.10, -1.50);
    glVertex3f (1.30, -0.10, -1.48);
    glVertex3f (1.30, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.30, -0.30, -1.50);
    glVertex3f (1.28, -0.30, -1.50);
    glVertex3f (1.28, -0.10, -1.50);
    glVertex3f (1.30, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.30, -0.10, -1.50);
    glVertex3f (1.28, -0.10, -1.50);
    glVertex3f (1.28, -0.10, -1.48);
    glVertex3f (1.30, -0.10, -1.48);
    glEnd();

    ///Boundry 15....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.48);
    glVertex3f (1.48, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.48);
    glVertex3f (1.50, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.50);
    glVertex3f (1.48, -0.30, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.48);
    glVertex3f (1.50, -0.10, -1.48);
    glEnd();

    ///Boundry Top....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.48);
    glVertex3f (1.48, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.48);
    glVertex3f (1.50, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glVertex3f (1.50, -0.08, -1.50);
    glVertex3f (-1.50, -0.08, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.08, -1.50);
    glVertex3f (1.50, -0.08, -1.50);
    glVertex3f (1.50, -0.08, -1.48);
    glVertex3f (-1.50, -0.08, -1.48);
    glEnd();


}
void BoundaryRight()
{

    ///Boundry Botton...
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.3, 1.50);
    glVertex3f (1.48, -0.3, 1.50);
    glVertex3f (1.48, -0.3, -1.50);
    glVertex3f (1.50, -0.3, -1.50);
    glEnd();
    ///Boundry 1....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 1.50);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.48, -0.10, 1.48);
    glVertex3f (1.48, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.50);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (1.50, -0.10, 1.48);
    glVertex3f (1.50, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.50);
    glVertex3f (1.48, -0.30, 1.50);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.50, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.48, -0.10, 1.48);
    glVertex3f (1.50, -0.10, 1.48);
    glEnd();


    ///Boundry 2....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 1.30);
    glVertex3f (1.48, -0.10, 1.30);
    glVertex3f (1.48, -0.10, 1.28);
    glVertex3f (1.48, -0.30, 1.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.30);
    glVertex3f (1.50, -0.10, 1.30);
    glVertex3f (1.50, -0.10, 1.28);
    glVertex3f (1.50, -0.30, 1.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.30);
    glVertex3f (1.48, -0.30, 1.30);
    glVertex3f (1.48, -0.10, 1.30);
    glVertex3f (1.50, -0.10, 1.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 1.30);
    glVertex3f (1.48, -0.10, 1.30);
    glVertex3f (1.48, -0.10, 1.28);
    glVertex3f (1.50, -0.10, 1.28);
    glEnd();

    ///Boundry 3....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 1.10);
    glVertex3f (1.48, -0.10, 1.10);
    glVertex3f (1.48, -0.10, 1.08);
    glVertex3f (1.48, -0.30, 1.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.10);
    glVertex3f (1.50, -0.10, 1.10);
    glVertex3f (1.50, -0.10, 1.08);
    glVertex3f (1.50, -0.30, 1.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 1.10);
    glVertex3f (1.48, -0.30, 1.10);
    glVertex3f (1.48, -0.10, 1.10);
    glVertex3f (1.50, -0.10, 1.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 1.10);
    glVertex3f (1.48, -0.10, 1.10);
    glVertex3f (1.48, -0.10, 1.08);
    glVertex3f (1.50, -0.10, 1.08);
    glEnd();

    ///Boundry 4....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 0.90);
    glVertex3f (1.48, -0.10, 0.90);
    glVertex3f (1.48, -0.10, 0.88);
    glVertex3f (1.48, -0.30, 0.88);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.90);
    glVertex3f (1.50, -0.10, 0.90);
    glVertex3f (1.50, -0.10, 0.88);
    glVertex3f (1.50, -0.30, 0.88);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.90);
    glVertex3f (1.48, -0.30, 0.90);
    glVertex3f (1.48, -0.10, 0.90);
    glVertex3f (1.50, -0.10, 0.90);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 0.90);
    glVertex3f (1.48, -0.10, 0.90);
    glVertex3f (1.48, -0.10, 0.88);
    glVertex3f (1.50, -0.10, 0.88);
    glEnd();


    ///Boundry 5....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 0.70);
    glVertex3f (1.48, -0.10, 0.70);
    glVertex3f (1.48, -0.10, 0.68);
    glVertex3f (1.48, -0.30, 0.68);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.70);
    glVertex3f (1.50, -0.10, 0.70);
    glVertex3f (1.50, -0.10, 0.68);
    glVertex3f (1.50, -0.30, 0.68);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.70);
    glVertex3f (1.48, -0.30, 0.70);
    glVertex3f (1.48, -0.10, 0.70);
    glVertex3f (1.50, -0.10, 0.70);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 0.70);
    glVertex3f (1.48, -0.10, 0.70);
    glVertex3f (1.48, -0.10, 0.68);
    glVertex3f (1.50, -0.10, 0.68);
    glEnd();

    ///Boundry 6....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 0.50);
    glVertex3f (1.48, -0.10, 0.50);
    glVertex3f (1.48, -0.10, 0.48);
    glVertex3f (1.48, -0.30, 0.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.50);
    glVertex3f (1.50, -0.10, 0.50);
    glVertex3f (1.50, -0.10, 0.48);
    glVertex3f (1.50, -0.30, 0.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.50);
    glVertex3f (1.48, -0.30, 0.50);
    glVertex3f (1.48, -0.10, 0.50);
    glVertex3f (1.50, -0.10, 0.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 0.50);
    glVertex3f (1.48, -0.10, 0.50);
    glVertex3f (1.48, -0.10, 0.48);
    glVertex3f (1.50, -0.10, 0.48);
    glEnd();


    ///Boundry 7....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 0.30);
    glVertex3f (1.48, -0.10, 0.30);
    glVertex3f (1.48, -0.10, 0.28);
    glVertex3f (1.48, -0.30, 0.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.30);
    glVertex3f (1.50, -0.10, 0.30);
    glVertex3f (1.50, -0.10, 0.28);
    glVertex3f (1.50, -0.30, 0.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.30);
    glVertex3f (1.48, -0.30, 0.30);
    glVertex3f (1.48, -0.10, 0.30);
    glVertex3f (1.50, -0.10, 0.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 0.30);
    glVertex3f (1.48, -0.10, 0.30);
    glVertex3f (1.48, -0.10, 0.28);
    glVertex3f (1.50, -0.10, 0.28);
    glEnd();


    ///Boundry 8....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, 0.10);
    glVertex3f (1.48, -0.10, 0.10);
    glVertex3f (1.48, -0.10, 0.08);
    glVertex3f (1.48, -0.30, 0.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.10);
    glVertex3f (1.50, -0.10, 0.10);
    glVertex3f (1.50, -0.10, 0.08);
    glVertex3f (1.50, -0.30, 0.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, 0.10);
    glVertex3f (1.48, -0.30, 0.10);
    glVertex3f (1.48, -0.10, 0.10);
    glVertex3f (1.50, -0.10, 0.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, 0.10);
    glVertex3f (1.48, -0.10, 0.10);
    glVertex3f (1.48, -0.10, 0.08);
    glVertex3f (1.50, -0.10, 0.08);
    glEnd();


    ///Boundry 9....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -0.10);
    glVertex3f (1.48, -0.10, -0.10);
    glVertex3f (1.48, -0.10, -0.08);
    glVertex3f (1.48, -0.30, -0.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.10);
    glVertex3f (1.50, -0.10, -0.10);
    glVertex3f (1.50, -0.10, -0.08);
    glVertex3f (1.50, -0.30, -0.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.10);
    glVertex3f (1.48, -0.30, -0.10);
    glVertex3f (1.48, -0.10, -0.10);
    glVertex3f (1.50, -0.10, -0.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -0.10);
    glVertex3f (1.48, -0.10, -0.10);
    glVertex3f (1.48, -0.10, -0.08);
    glVertex3f (1.50, -0.10, -0.08);
    glEnd();


    ///Boundry 10....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -0.30);
    glVertex3f (1.48, -0.10, -0.30);
    glVertex3f (1.48, -0.10, -0.28);
    glVertex3f (1.48, -0.30, -0.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.30);
    glVertex3f (1.50, -0.10, -0.30);
    glVertex3f (1.50, -0.10, -0.28);
    glVertex3f (1.50, -0.30, -0.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.30);
    glVertex3f (1.48, -0.30, -0.30);
    glVertex3f (1.48, -0.10, -0.30);
    glVertex3f (1.50, -0.10, -0.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -0.30);
    glVertex3f (1.48, -0.10, -0.30);
    glVertex3f (1.48, -0.10, -0.28);
    glVertex3f (1.50, -0.10, -0.28);
    glEnd();


    ///Boundry 11....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -0.50);
    glVertex3f (1.48, -0.10, -0.50);
    glVertex3f (1.48, -0.10, -0.48);
    glVertex3f (1.48, -0.30, -0.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.50);
    glVertex3f (1.50, -0.10, -0.50);
    glVertex3f (1.50, -0.10, -0.48);
    glVertex3f (1.50, -0.30, -0.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.50);
    glVertex3f (1.48, -0.30, -0.50);
    glVertex3f (1.48, -0.10, -0.50);
    glVertex3f (1.50, -0.10, -0.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -0.50);
    glVertex3f (1.48, -0.10, -0.50);
    glVertex3f (1.48, -0.10, -0.48);
    glVertex3f (1.50, -0.10, -0.48);
    glEnd();

    ///Boundry 12....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -0.70);
    glVertex3f (1.48, -0.10, -0.70);
    glVertex3f (1.48, -0.10, -0.68);
    glVertex3f (1.48, -0.30, -0.68);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.70);
    glVertex3f (1.50, -0.10, -0.70);
    glVertex3f (1.50, -0.10, -0.68);
    glVertex3f (1.50, -0.30, -0.68);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.70);
    glVertex3f (1.48, -0.30, -0.70);
    glVertex3f (1.48, -0.10, -0.70);
    glVertex3f (1.50, -0.10, -0.70);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -0.70);
    glVertex3f (1.48, -0.10, -0.70);
    glVertex3f (1.48, -0.10, -0.68);
    glVertex3f (1.50, -0.10, -0.68);
    glEnd();


    ///Boundry 13....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -0.90);
    glVertex3f (1.48, -0.10, -0.90);
    glVertex3f (1.48, -0.10, -0.88);
    glVertex3f (1.48, -0.30, -0.88);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.90);
    glVertex3f (1.50, -0.10, -0.90);
    glVertex3f (1.50, -0.10, -0.88);
    glVertex3f (1.50, -0.30, -0.88);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -0.90);
    glVertex3f (1.48, -0.30, -0.90);
    glVertex3f (1.48, -0.10, -0.90);
    glVertex3f (1.50, -0.10, -0.90);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -0.90);
    glVertex3f (1.48, -0.10, -0.90);
    glVertex3f (1.48, -0.10, -0.88);
    glVertex3f (1.50, -0.10, -0.88);
    glEnd();


    ///Boundry 14....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -1.10);
    glVertex3f (1.48, -0.10, -1.10);
    glVertex3f (1.48, -0.10, -1.08);
    glVertex3f (1.48, -0.30, -1.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.10);
    glVertex3f (1.50, -0.10, -1.10);
    glVertex3f (1.50, -0.10, -1.08);
    glVertex3f (1.50, -0.30, -1.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.10);
    glVertex3f (1.48, -0.30, -1.10);
    glVertex3f (1.48, -0.10, -1.10);
    glVertex3f (1.50, -0.10, -1.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -1.10);
    glVertex3f (1.48, -0.10, -1.10);
    glVertex3f (1.48, -0.10, -1.08);
    glVertex3f (1.50, -0.10, -1.08);
    glEnd();


    ///Boundry 15....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -1.30);
    glVertex3f (1.48, -0.10, -1.30);
    glVertex3f (1.48, -0.10, -1.28);
    glVertex3f (1.48, -0.30, -1.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.30);
    glVertex3f (1.50, -0.10, -1.30);
    glVertex3f (1.50, -0.10, -1.28);
    glVertex3f (1.50, -0.30, -1.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.30);
    glVertex3f (1.48, -0.30, -1.30);
    glVertex3f (1.48, -0.10, -1.30);
    glVertex3f (1.50, -0.10, -1.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -1.30);
    glVertex3f (1.48, -0.10, -1.30);
    glVertex3f (1.48, -0.10, -1.28);
    glVertex3f (1.50, -0.10, -1.28);
    glEnd();


    ///Boundry 16....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.30, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.48);
    glVertex3f (1.48, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.30, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.48);
    glVertex3f (1.50, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (1.50, -0.30, -1.50);
    glVertex3f (1.48, -0.30, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.48, -0.10, -1.48);
    glVertex3f (1.50, -0.10, -1.48);
    glEnd();

    ///Boundary Top....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.48, -0.10, 1.50);
    glVertex3f (1.48, -0.08, 1.50);
    glVertex3f (1.48, -0.08, -1.58);
    glVertex3f (1.48, -0.10, -1.58);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (1.50, -0.10, 1.50);
    glVertex3f (1.50, -0.08, 1.50);
    glVertex3f (1.50, -0.08, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (1.50, -0.30, -1.50);
    glVertex3f (1.48, -0.30, -1.50);
    glVertex3f (1.48, -0.10, -1.50);
    glVertex3f (1.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.50, -0.08, 1.50);
    glVertex3f (1.48, -0.08, 1.50);
    glVertex3f (1.48, -0.08, -1.50);
    glVertex3f (1.50, -0.08, -1.50);
    glEnd();


}
void BoundaryLeft()
{

    ///Boundry Bottom
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.3, 1.50);
    glVertex3f (-1.48, -0.3, 1.50);
    glVertex3f (-1.48, -0.3, -1.50);
    glVertex3f (-1.50, -0.3, -1.50);
    glEnd();

    ///Boundry 1....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 1.50);
    glVertex3f (-1.48, -0.10, 1.50);
    glVertex3f (-1.48, -0.10, 1.48);
    glVertex3f (-1.48, -0.30, 1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 1.50);
    glVertex3f (-1.50, -0.10, 1.50);
    glVertex3f (-1.50, -0.10, 1.48);
    glVertex3f (-1.50, -0.30, 1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 1.50);
    glVertex3f (-1.48, -0.30, 1.50);
    glVertex3f (-1.48, -0.10, 1.50);
    glVertex3f (-1.50, -0.10, 1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 1.50);
    glVertex3f (-1.48, -0.10, 1.50);
    glVertex3f (-1.48, -0.10, 1.48);
    glVertex3f (-1.50, -0.10, 1.48);
    glEnd();


    ///Boundry 2....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 1.30);
    glVertex3f (-1.48, -0.10, 1.30);
    glVertex3f (-1.48, -0.10, 1.28);
    glVertex3f (-1.48, -0.30, 1.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 1.30);
    glVertex3f (-1.50, -0.10, 1.30);
    glVertex3f (-1.50, -0.10, 1.28);
    glVertex3f (-1.50, -0.30, 1.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 1.30);
    glVertex3f (-1.48, -0.30, 1.30);
    glVertex3f (-1.48, -0.10, 1.30);
    glVertex3f (-1.50, -0.10, 1.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 1.30);
    glVertex3f (-1.48, -0.10, 1.30);
    glVertex3f (-1.48, -0.10, 1.28);
    glVertex3f (-1.50, -0.10, 1.28);
    glEnd();

    ///Boundry 3....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 1.10);
    glVertex3f (-1.48, -0.10, 1.10);
    glVertex3f (-1.48, -0.10, 1.08);
    glVertex3f (-1.48, -0.30, 1.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 1.10);
    glVertex3f (-1.50, -0.10, 1.10);
    glVertex3f (-1.50, -0.10, 1.08);
    glVertex3f (-1.50, -0.30, 1.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 1.10);
    glVertex3f (-1.48, -0.30, 1.10);
    glVertex3f (-1.48, -0.10, 1.10);
    glVertex3f (-1.50, -0.10, 1.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 1.10);
    glVertex3f (-1.48, -0.10, 1.10);
    glVertex3f (-1.48, -0.10, 1.08);
    glVertex3f (-1.50, -0.10, 1.08);
    glEnd();

    ///Boundry 4....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 0.90);
    glVertex3f (-1.48, -0.10, 0.90);
    glVertex3f (-1.48, -0.10, 0.88);
    glVertex3f (-1.48, -0.30, 0.88);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.90);
    glVertex3f (-1.50, -0.10, 0.90);
    glVertex3f (-1.50, -0.10, 0.88);
    glVertex3f (-1.50, -0.30, 0.88);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.90);
    glVertex3f (-1.48, -0.30, 0.90);
    glVertex3f (-1.48, -0.10, 0.90);
    glVertex3f (-1.50, -0.10, 0.90);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 0.90);
    glVertex3f (-1.48, -0.10, 0.90);
    glVertex3f (-1.48, -0.10, 0.88);
    glVertex3f (-1.50, -0.10, 0.88);
    glEnd();


    ///Boundry 5....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 0.70);
    glVertex3f (-1.48, -0.10, 0.70);
    glVertex3f (-1.48, -0.10, 0.68);
    glVertex3f (-1.48, -0.30, 0.68);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.70);
    glVertex3f (-1.50, -0.10, 0.70);
    glVertex3f (-1.50, -0.10, 0.68);
    glVertex3f (-1.50, -0.30, 0.68);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.70);
    glVertex3f (-1.48, -0.30, 0.70);
    glVertex3f (-1.48, -0.10, 0.70);
    glVertex3f (-1.50, -0.10, 0.70);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 0.70);
    glVertex3f (-1.48, -0.10, 0.70);
    glVertex3f (-1.48, -0.10, 0.68);
    glVertex3f (-1.50, -0.10, 0.68);
    glEnd();

    ///Boundry 6....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 0.50);
    glVertex3f (-1.48, -0.10, 0.50);
    glVertex3f (-1.48, -0.10, 0.48);
    glVertex3f (-1.48, -0.30, 0.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.50);
    glVertex3f (-1.50, -0.10, 0.50);
    glVertex3f (-1.50, -0.10, 0.48);
    glVertex3f (-1.50, -0.30, 0.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.50);
    glVertex3f (-1.48, -0.30, 0.50);
    glVertex3f (-1.48, -0.10, 0.50);
    glVertex3f (-1.50, -0.10, 0.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 0.50);
    glVertex3f (-1.48, -0.10, 0.50);
    glVertex3f (-1.48, -0.10, 0.48);
    glVertex3f (-1.50, -0.10, 0.48);
    glEnd();


    ///Boundry 7....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 0.30);
    glVertex3f (-1.48, -0.10, 0.30);
    glVertex3f (-1.48, -0.10, 0.28);
    glVertex3f (-1.48, -0.30, 0.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.30);
    glVertex3f (-1.50, -0.10, 0.30);
    glVertex3f (-1.50, -0.10, 0.28);
    glVertex3f (-1.50, -0.30, 0.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.30);
    glVertex3f (-1.48, -0.30, 0.30);
    glVertex3f (-1.48, -0.10, 0.30);
    glVertex3f (-1.50, -0.10, 0.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 0.30);
    glVertex3f (-1.48, -0.10, 0.30);
    glVertex3f (-1.48, -0.10, 0.28);
    glVertex3f (-1.50, -0.10, 0.28);
    glEnd();


    ///Boundry 8....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, 0.10);
    glVertex3f (-1.48, -0.10, 0.10);
    glVertex3f (-1.48, -0.10, 0.08);
    glVertex3f (-1.48, -0.30, 0.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.10);
    glVertex3f (-1.50, -0.10, 0.10);
    glVertex3f (-1.50, -0.10, 0.08);
    glVertex3f (-1.50, -0.30, 0.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, 0.10);
    glVertex3f (-1.48, -0.30, 0.10);
    glVertex3f (-1.48, -0.10, 0.10);
    glVertex3f (-1.50, -0.10, 0.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, 0.10);
    glVertex3f (-1.48, -0.10, 0.10);
    glVertex3f (-1.48, -0.10, 0.08);
    glVertex3f (-1.50, -0.10, 0.08);
    glEnd();


    ///Boundry 9....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -0.10);
    glVertex3f (-1.48, -0.10, -0.10);
    glVertex3f (-1.48, -0.10, -0.08);
    glVertex3f (-1.48, -0.30, -0.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.10);
    glVertex3f (-1.50, -0.10, -0.10);
    glVertex3f (-1.50, -0.10, -0.08);
    glVertex3f (-1.50, -0.30, -0.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.10);
    glVertex3f (-1.48, -0.30, -0.10);
    glVertex3f (-1.48, -0.10, -0.10);
    glVertex3f (-1.50, -0.10, -0.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -0.10);
    glVertex3f (-1.48, -0.10, -0.10);
    glVertex3f (-1.48, -0.10, -0.08);
    glVertex3f (-1.50, -0.10, -0.08);
    glEnd();


    ///Boundry 10....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -0.30);
    glVertex3f (-1.48, -0.10, -0.30);
    glVertex3f (-1.48, -0.10, -0.28);
    glVertex3f (-1.48, -0.30, -0.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.30);
    glVertex3f (-1.50, -0.10, -0.30);
    glVertex3f (-1.50, -0.10, -0.28);
    glVertex3f (-1.50, -0.30, -0.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.30);
    glVertex3f (-1.48, -0.30, -0.30);
    glVertex3f (-1.48, -0.10, -0.30);
    glVertex3f (-1.50, -0.10, -0.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -0.30);
    glVertex3f (-1.48, -0.10, -0.30);
    glVertex3f (-1.48, -0.10, -0.28);
    glVertex3f (-1.50, -0.10, -0.28);
    glEnd();


    ///Boundry 11....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -0.50);
    glVertex3f (-1.48, -0.10, -0.50);
    glVertex3f (-1.48, -0.10, -0.48);
    glVertex3f (-1.48, -0.30, -0.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.50);
    glVertex3f (-1.50, -0.10, -0.50);
    glVertex3f (-1.50, -0.10, -0.48);
    glVertex3f (-1.50, -0.30, -0.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.50);
    glVertex3f (-1.48, -0.30, -0.50);
    glVertex3f (-1.48, -0.10, -0.50);
    glVertex3f (-1.50, -0.10, -0.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -0.50);
    glVertex3f (-1.48, -0.10, -0.50);
    glVertex3f (-1.48, -0.10, -0.48);
    glVertex3f (-1.50, -0.10, -0.48);
    glEnd();

    ///Boundry 12....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -0.70);
    glVertex3f (-1.48, -0.10, -0.70);
    glVertex3f (-1.48, -0.10, -0.68);
    glVertex3f (-1.48, -0.30, -0.68);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.70);
    glVertex3f (-1.50, -0.10, -0.70);
    glVertex3f (-1.50, -0.10, -0.68);
    glVertex3f (-1.50, -0.30, -0.68);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.70);
    glVertex3f (-1.48, -0.30, -0.70);
    glVertex3f (-1.48, -0.10, -0.70);
    glVertex3f (-1.50, -0.10, -0.70);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -0.70);
    glVertex3f (-1.48, -0.10, -0.70);
    glVertex3f (-1.48, -0.10, -0.68);
    glVertex3f (-1.50, -0.10, -0.68);
    glEnd();


    ///Boundry 13....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -0.90);
    glVertex3f (-1.48, -0.10, -0.90);
    glVertex3f (-1.48, -0.10, -0.88);
    glVertex3f (-1.48, -0.30, -0.88);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.90);
    glVertex3f (-1.50, -0.10, -0.90);
    glVertex3f (-1.50, -0.10, -0.88);
    glVertex3f (-1.50, -0.30, -0.88);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -0.90);
    glVertex3f (-1.48, -0.30, -0.90);
    glVertex3f (-1.48, -0.10, -0.90);
    glVertex3f (-1.50, -0.10, -0.90);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -0.90);
    glVertex3f (-1.48, -0.10, -0.90);
    glVertex3f (-1.48, -0.10, -0.88);
    glVertex3f (-1.50, -0.10, -0.88);
    glEnd();


    ///Boundry 14....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -1.10);
    glVertex3f (-1.48, -0.10, -1.10);
    glVertex3f (-1.48, -0.10, -1.08);
    glVertex3f (-1.48, -0.30, -1.08);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.10);
    glVertex3f (-1.50, -0.10, -1.10);
    glVertex3f (-1.50, -0.10, -1.08);
    glVertex3f (-1.50, -0.30, -1.08);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.10);
    glVertex3f (-1.48, -0.30, -1.10);
    glVertex3f (-1.48, -0.10, -1.10);
    glVertex3f (-1.50, -0.10, -1.10);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -1.10);
    glVertex3f (-1.48, -0.10, -1.10);
    glVertex3f (-1.48, -0.10, -1.08);
    glVertex3f (-1.50, -0.10, -1.08);
    glEnd();


    ///Boundry 15....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -1.30);
    glVertex3f (-1.48, -0.10, -1.30);
    glVertex3f (-1.48, -0.10, -1.28);
    glVertex3f (-1.48, -0.30, -1.28);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.30);
    glVertex3f (-1.50, -0.10, -1.30);
    glVertex3f (-1.50, -0.10, -1.28);
    glVertex3f (-1.50, -0.30, -1.28);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.30);
    glVertex3f (-1.48, -0.30, -1.30);
    glVertex3f (-1.48, -0.10, -1.30);
    glVertex3f (-1.50, -0.10, -1.30);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -1.30);
    glVertex3f (-1.48, -0.10, -1.30);
    glVertex3f (-1.48, -0.10, -1.28);
    glVertex3f (-1.50, -0.10, -1.28);
    glEnd();


    ///Boundry 16....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.30, -1.50);
    glVertex3f (-1.48, -0.10, -1.50);
    glVertex3f (-1.48, -0.10, -1.48);
    glVertex3f (-1.48, -0.30, -1.48);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.50);
    glVertex3f (-1.50, -0.10, -1.50);
    glVertex3f (-1.50, -0.10, -1.48);
    glVertex3f (-1.50, -0.30, -1.48);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.50);
    glVertex3f (-1.48, -0.30, -1.50);
    glVertex3f (-1.48, -0.10, -1.50);
    glVertex3f (-1.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.10, -1.50);
    glVertex3f (-1.48, -0.10, -1.50);
    glVertex3f (-1.48, -0.10, -1.48);
    glVertex3f (-1.50, -0.10, -1.48);
    glEnd();


    ///Boundary Top....

    //Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.48, -0.10, 1.50);
    glVertex3f (-1.48, -0.08, 1.50);
    glVertex3f (-1.48, -0.08, -1.58);
    glVertex3f (-1.48, -0.10, -1.58);
    glEnd();
    //Left
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.10, 1.50);
    glVertex3f (-1.50, -0.08, 1.50);
    glVertex3f (-1.50, -0.08, -1.50);
    glVertex3f (-1.50, -0.10, -1.50);
    glEnd();
    //Front
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-1.50, -0.30, -1.50);
    glVertex3f (-1.48, -0.30, -1.50);
    glVertex3f (-1.48, -0.10, -1.50);
    glVertex3f (-1.50, -0.10, -1.50);
    glEnd();
    //Top
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-1.50, -0.08, 1.50);
    glVertex3f (-1.48, -0.08, 1.50);
    glVertex3f (-1.48, -0.08, -1.50);
    glVertex3f (-1.50, -0.08, -1.50);
    glEnd();

}
void WuduPlace()
{

    ///Right
    glBegin(GL_QUADS);
    glColor3f (.960, 0.949, 0.815);
    glVertex3f (1.1, -0.20, 1.2);
    glVertex3f (1.1, -0.30, 1.2);
    glVertex3f (1.1, -0.30, .5);
    glVertex3f (1.1, -0.20,  .5);


    ///Left
    glBegin(GL_QUADS);
    glColor3f (1, 0, 0);
    glVertex3f (1, -0.20, 1.2);
    glVertex3f (1, -0.30, 1.2);
    glVertex3f (1, -0.30, .5);
    glVertex3f (1, -0.20,  .5);



    ///Front
    glBegin(GL_QUADS);
    glColor3f (0, 0, 1);
    glVertex3f (1, -0.30, 1.2);
    glVertex3f (1.1, -0.30, 1.2);
    glVertex3f (1.1, -0.20, 1.2);
    glVertex3f (1, -0.20,  1.2);

    ///Top
    glBegin(GL_QUADS);
    glColor3f (.627, .627, .627);
    glVertex3f (1.1, -0.20, 1.2);
    glVertex3f (1, -0.20, 1.2);
    glVertex3f (1, -0.20, .5);
    glVertex3f (1.1,-0.20,  .5);


    ///Seat 1

    ///Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (.95, -0.20, .64);
    glVertex3f (.95, -0.30, .64);
    glVertex3f (.95, -0.30, .60);
    glVertex3f (.95, -0.20, .60);

    ///Left
    glBegin(GL_QUADS);
    glColor3f (0, 1.0, 1.0);
    glVertex3f (.9, -0.20, .64);
    glVertex3f (.9, -0.30, .64);
    glVertex3f (.9, -0.30, .60);
    glVertex3f (.9, -0.20, .60);



    ///Front
    glBegin(GL_QUADS);
    glColor3f (0, 0, 1);
    glVertex3f (.9, -0.30, .64);
    glVertex3f (.95, -0.30, .64);
    glVertex3f (.95, -0.20, .64);
    glVertex3f (.9, -0.20,  .64);

    ///Top
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.95, -0.20, .64);
    glVertex3f (.90, -0.20, .64);
    glVertex3f (.90, -0.20, .60);
    glVertex3f (.95,-0.20,  .60);



    ///Seat 2

    ///Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (.95, -0.20, .76);
    glVertex3f (.95, -0.30, .76);
    glVertex3f (.95, -0.30, .72);
    glVertex3f (.95, -0.20, .72);

    ///Left
    glBegin(GL_QUADS);
    glColor3f (0, 1.0, 1.0);
    glVertex3f (.9, -0.20, .76);
    glVertex3f (.9, -0.30, .76);
    glVertex3f (.9, -0.30, .72);
    glVertex3f (.9, -0.20, .72);



    ///Front
    glBegin(GL_QUADS);
    glColor3f (0, 0, 1);
    glVertex3f (.9, -0.30, .76);
    glVertex3f (.95, -0.30, .76);
    glVertex3f (.95, -0.20, .76);
    glVertex3f (.9, -0.20,  .76);

    ///Top
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.95, -0.20, .76);
    glVertex3f (.90, -0.20, .76);
    glVertex3f (.90, -0.20, .72);
    glVertex3f (.95,-0.20,  .72);


    ///Seat 3

    ///Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (.95, -0.20, .88);
    glVertex3f (.95, -0.30, .88);
    glVertex3f (.95, -0.30, .84);
    glVertex3f (.95, -0.20, .84);

    ///Left
    glBegin(GL_QUADS);
    glColor3f (0, 1.0, 1.0);
    glVertex3f (.9, -0.20, .88);
    glVertex3f (.9, -0.30, .88);
    glVertex3f (.9, -0.30, .84);
    glVertex3f (.9, -0.20, .84);



    ///Front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.9, -0.30, .88);
    glVertex3f (.95, -0.30, .88);
    glVertex3f (.95, -0.20, .88);
    glVertex3f (.9, -0.20,  .88);

    ///Top
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.95, -0.20, .88);
    glVertex3f (.90, -0.20, .88);
    glVertex3f (.90, -0.20, .84);
    glVertex3f (.95,-0.20,  .84);



    ///Seat 4

    ///Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (.95, -0.20, 1);
    glVertex3f (.95, -0.30, 1);
    glVertex3f (.95, -0.30, .96);
    glVertex3f (.95, -0.20, .96);

    ///Left
    glBegin(GL_QUADS);
    glColor3f (0, 1.0, 1.0);
    glVertex3f (.9, -0.20, 1);
    glVertex3f (.9, -0.30, 1);
    glVertex3f (.9, -0.30, .96);
    glVertex3f (.9, -0.20, .96);



    ///Front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.9, -0.30, 1);
    glVertex3f (.95, -0.30, 1);
    glVertex3f (.95, -0.20, 1);
    glVertex3f (.9, -0.20, 1);

    ///Top
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.95, -0.20, 1);
    glVertex3f (.90, -0.20, 1);
    glVertex3f (.90, -0.20, .96);
    glVertex3f (.95,-0.20,  .96);

    ///Seat 5

    ///Right
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 0.0);
    glVertex3f (.95, -0.20, 1.12);
    glVertex3f (.95, -0.30, 1.12);
    glVertex3f (.95, -0.30, 1.08);
    glVertex3f (.95, -0.20, 1.08);

    ///Left
    glBegin(GL_QUADS);
    glColor3f (0, 1.0, 1.0);
    glVertex3f (.9, -0.20, 1.12);
    glVertex3f (.9, -0.30, 1.12);
    glVertex3f (.9, -0.30, 1.08);
    glVertex3f (.9, -0.20, 1.08);



    ///Front
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f (.9, -0.30, 1.12);
    glVertex3f (.95, -0.30, 1.12);
    glVertex3f (.95, -0.20, 1.12);
    glVertex3f (.9, -0.20, 1.12);

    ///Top
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (.95, -0.20, 1.12);
    glVertex3f (.90, -0.20, 1.12);
    glVertex3f (.90, -0.20, 1.08);
    glVertex3f (.95,-0.20,  1.08);
}

void Mosque()
{


    ///Right border black....
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (1.3, 0.3, 0.25);
    glVertex3f (1.3, -0.3, 0.25);
    glVertex3f (1.3, -0.3, -0.25);
    glVertex3f (1.3, 0.3, -0.25);

    ///Right....
    glBegin(GL_QUADS);
    glColor3f (0.2, 1, 1);
    glVertex3f (1.3, 0.28, 0.23);
    glVertex3f (1.3, -0.28, 0.23);
    glVertex3f (1.3, -0.28, -0.23);
    glVertex3f (1.3, 0.28, -0.23);

    ///Window right
    glBegin(GL_QUADS);
    glColor3f (0.12, 0.12, 0.12);
    glVertex3f (1.3, -0.15, 0.20);
    glVertex3f (1.3, 0.15, 0.20);
    glVertex3f (1.3, 0.15, -0.20);
    glVertex3f (1.3, -0.15, -0.20);
    ///Window Devidor
    glBegin(GL_QUADS);
    glColor3f (0.2, 1, 1);
    glVertex3f (1.3, -0.15, 0.01);
    glVertex3f (1.3, 0.15, 0.01);
    glVertex3f (1.3, 0.15, -0.01);
    glVertex3f (1.3, -0.15, -0.01);

    glEnd();

    ///Top....
    glBegin(GL_QUADS);
    glColor3f (0, .8, .4);
    glVertex3f (.20, 0.3, 0.25);
    glVertex3f (1.3, 0.3, 0.25);
    glVertex3f (1.3, 0.3, -0.25);
    glVertex3f (.20, 0.3, -0.25);
    glEnd();

    ///Dome
    glColor3f (0, .8, .4);
    glPushMatrix();
    glTranslatef(.8, .3, 0);
    glutSolidSphere(0.3,100,100);
    glPopMatrix();


    ///Dome Chad front....
    glBegin(GL_QUADS);
    glColor3f (0, .8, .4);
    glVertex3f (0.81, 0.3, 0.00);
    glVertex3f (0.82, 0.3, 0.00);
    glVertex3f (0.82, 0.7, 0.00);
    glVertex3f (0.81, 0.7, 0.00);

    ///Left border black......
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.20, -0.3, 0.25);
    glVertex3f (.20, 0.3, 0.25);
    glVertex3f (.20, 0.3, -0.25);
    glVertex3f (.20, -0.3, -0.25);

    ///Left......
    glBegin(GL_QUADS);
    glColor3f (0.2, 1, 1);
    glVertex3f (.20, -0.28, 0.23);
    glVertex3f (.20, 0.28, 0.23);
    glVertex3f (.20, 0.28, -0.23);
    glVertex3f (.20, -0.28, -0.23);

    ///Window Left
    glBegin(GL_QUADS);
    glColor3f (.12, .12, .12);
    glVertex3f (.20, -0.10, 0.20);
    glVertex3f (.20, 0.15, 0.20);
    glVertex3f (.20, 0.15, -0.20);
    glVertex3f (.20, -0.10, -0.20);
    ///Window Devidor
    glBegin(GL_QUADS);
    glColor3f (0.2, 1, 1);
    glVertex3f (.20, -0.10, 0.01);
    glVertex3f (.20, 0.15, 0.01);
    glVertex3f (.20, 0.15, -0.01);
    glVertex3f (.20, -0.10, -0.01);

    glEnd();

    ///Front border black......
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.20, -0.3, 0.25);
    glVertex3f (1.3, -0.3, 0.25);
    glVertex3f (1.3, 0.3, 0.25);
    glVertex3f (.20, 0.3, 0.25);
    glEnd();

    ///Front......
    glBegin(GL_QUADS);
    glColor3f (0.2, 1, 1);
    glVertex3f (.22, -0.3, 0.25);
    glVertex3f (1.28, -0.3, 0.25);
    glVertex3f (1.28, 0.28, 0.25);
    glVertex3f (.22, 0.28, 0.25);
    glEnd();





    ///Window
    ///Left
    glBegin(GL_QUADS);
    glColor3f (.12, .12, .12);
    glVertex3f (.28, -0.10, 0.25);
    glVertex3f (.55, -0.10, 0.25);
    glVertex3f (.55, 0.15, 0.25);
    glVertex3f (.28, 0.15, 0.25);
    glEnd();
    ///Right
    glBegin(GL_QUADS);
    glColor3f (.12, .12, .12);
    glVertex3f (.95, -0.10, 0.25);
    glVertex3f (1.22, -0.10, 0.25);
    glVertex3f (1.22, 0.15, 0.25);
    glVertex3f (.95, 0.15, 0.25);
    glEnd();


    ///Boor Back
    glBegin(GL_QUADS);
    glColor3f (.12, .12, .12);
    glVertex3f (.65, -0.30, 0.25);
    glVertex3f (.85, -0.30, 0.25);
    glVertex3f (.85, 0.15, 0.25);
    glVertex3f (.65, 0.15, 0.25);
    glEnd();


    glBegin(GL_QUADS);


    glEnd();

}

void Door()
{
    ///Door.......

    glBegin(GL_QUADS);
    glColor3f (1, 1, 1);
    glVertex3f (.65, -0.3, 0.25);
    glVertex3f (.85, -0.3, 0.25);
    glVertex3f (.85, -0.28, 0.25);
    glVertex3f (.65, -0.28, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (1, 0.8, .898);
    glVertex3f (.67, -0.28, 0.25);
    glVertex3f (.83, -0.28, 0.25);
    glVertex3f (.83, 0.13, 0.25);
    glVertex3f (.67, 0.13, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (1, 1, 1);
    glVertex3f (.65, 0.13, 0.25);
    glVertex3f (.85, 0.13, 0.25);
    glVertex3f (.85, 0.15, 0.25);
    glVertex3f (.65, 0.15, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (1, 1, 1);
    glVertex3f (.65, -0.3, 0.25);
    glVertex3f (.67, -0.3, 0.25);
    glVertex3f (.67, 0.15, 0.25);
    glVertex3f (.65, 0.15, 0.25);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f (1, 1, 1);
    glVertex3f (.83, -0.3, 0.25);
    glVertex3f (.85, -0.3, 0.25);
    glVertex3f (.85, 0.15, 0.25);
    glVertex3f (.83, 0.15, 0.25);
    glEnd();

}

void Pond()
{
     ///top
     glBegin(GL_QUADS);
     glColor3f (1.0, 0.0, 0.0);
     glVertex3f (-0.70, -0.2, 0.50);
     glVertex3f (-1.2, -0.2, 0.50);
     glVertex3f (-1.2, -0.2, -0.30);
     glVertex3f (-0.70,-0.2, -0.30);
     glEnd();


    ///backside

    glBegin(GL_QUADS);
    glColor3f (.7, .7, .7);
    glVertex3f (-1.2, -0.3, -0.30);
    glVertex3f (-.70, -0.3, -0.30);
    glVertex3f (-.70, -0.6, -0.30);
    glVertex3f (-1.2, -0.6, -0.30);
    glEnd();



    ///right

    glBegin(GL_QUADS);
    glColor3f (.7, .7, .7);
    glVertex3f (-.70, -0.3, 0.50);
    glVertex3f (-.70, -0.3, -0.30);
    glVertex3f (-.70, -0.6, -0.30);
    glVertex3f (-.70, -0.6, 0.50);

    glEnd();



    ///left

    glBegin(GL_QUADS);
    glColor3f (0.7, 0.7, 0.7);
    glVertex3f (-1.2, -0.3, 0.50);
    glVertex3f (-1.2, -0.3, -0.30);
    glVertex3f (-1.2, -0.6, -0.30);
    glVertex3f (-1.2, -0.6, 0.50);

    glEnd();
    ///top
    glBegin(GL_QUADS);
     ///glColor3f (0.137255, 0.556863, 0.419608);
    glColor3f (0, .46,.745);
    glVertex3f (-0.70, -0.34, 0.50);
    glVertex3f (-1.2, -0.34, 0.50);
    glVertex3f (-1.2, -0.34, -0.30);
    glVertex3f (-0.70, -0.34, -0.30);
    glEnd();

    ///front

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 1.0);

    glVertex3f (-1.2, -0.3, 0.50);
    glVertex3f (-.70, -0.3, 0.50);
    glVertex3f (-.70, -0.6, 0.50);
    glVertex3f (-1.2, -0.6, 0.50);

    glEnd();
}

void Minar()
{
    ///Minar

    ///Minar right....
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.95, 0.3, 0.05);
    glVertex3f (0.95, 0.9, 0.05);
    glVertex3f (0.95, 0.9, 0.00);
    glVertex3f (0.95, 0.3, 0.00);

    ///Minar left....
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.9, 0.3, 0.05);
    glVertex3f (0.9, 0.9, 0.05);
    glVertex3f (0.9, 0.9, 0.00);
    glVertex3f (0.9, 0.3, 0.00);
    ///Minar front....
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (0.9, 0.3, 0.05);
    glVertex3f (0.95, 0.3, 0.05);
    glVertex3f (0.95, 0.9, 0.05);
    glVertex3f (0.9, 0.9, 0.05);

    ///Minar front STEP....
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.34, 0.05);
    glVertex3f (0.95, 0.34, 0.05);
    glVertex3f (0.95, 0.35, 0.05);
    glVertex3f (0.9, 0.35, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.40, 0.05);
    glVertex3f (0.95, 0.40, 0.05);
    glVertex3f (0.95, 0.41, 0.05);
    glVertex3f (0.9, 0.41, 0.05);


    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.46, 0.05);
    glVertex3f (0.95, 0.46, 0.05);
    glVertex3f (0.95, 0.47, 0.05);
    glVertex3f (0.9, 0.47, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.52, 0.05);
    glVertex3f (0.95, 0.52, 0.05);
    glVertex3f (0.95, 0.53, 0.05);
    glVertex3f (0.9, 0.53, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.58, 0.05);
    glVertex3f (0.95, 0.58, 0.05);
    glVertex3f (0.95, 0.59, 0.05);
    glVertex3f (0.9, 0.59, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.64, 0.05);
    glVertex3f (0.95, 0.64, 0.05);
    glVertex3f (0.95, 0.65, 0.05);
    glVertex3f (0.9, 0.65, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.70, 0.05);
    glVertex3f (0.95, 0.70, 0.05);
    glVertex3f (0.95, 0.71, 0.05);
    glVertex3f (0.9, 0.71, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.76, 0.05);
    glVertex3f (0.95, 0.76, 0.05);
    glVertex3f (0.95, 0.77, 0.05);
    glVertex3f (0.9, 0.77, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.82, 0.05);
    glVertex3f (0.95, 0.82, 0.05);
    glVertex3f (0.95, 0.83, 0.05);
    glVertex3f (0.9, 0.83, 0.05);

    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (0.9, 0.88, 0.05);
    glVertex3f (0.95, 0.88, 0.05);
    glVertex3f (0.95, 0.89, 0.05);
    glVertex3f (0.9, 0.89, 0.05);



     ///Minar Dome parking Function

     /*///Dome
     glColor3f (1.0, 1.0, 1.0);
     glPushMatrix();
     glScalef(1,1,1);
     glTranslatef(.925, .9, 0);
     glutSolidSphere(0.05,100,100);
     glPopMatrix();*/


}

void Parking()
{
    ///Dome
    glColor3f (1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(.935, .92, 0);
    glutSolidSphere(0.035,100,100);
    glPopMatrix();

    ///parking....
    glBegin(GL_QUADS);
    glColor3f (0.2, 0.2, 0.2);
    glVertex3f (.20, -0.3, 0.35);
    glVertex3f (-.35, -0.3, 0.35);
    glVertex3f (-.35, -0.3, -0.50);
    glVertex3f (.20,-0.3, -0.50);

    glEnd();

    ///Parking Road
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (-.22, -0.3, 0.25);
    glVertex3f (0.02, -0.3, 0.25);
    glVertex3f (0.02, -0.3, 1.80);
    glVertex3f (-.22, -0.3, 1.80);

    glEnd();

    ///Parking Road line 1
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.105, -0.3, 0.25);
    glVertex3f (-0.095, -0.3, 0.25);
    glVertex3f (-0.095, -0.3, 0.55);
    glVertex3f (-.105, -0.3, 0.55);
    glEnd();

    ///Parking Road line 2
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.105, -0.3, 0.65);
    glVertex3f (-0.095, -0.3, 0.65);
    glVertex3f (-0.095, -0.3, 0.95);
    glVertex3f (-.105, -0.3, 0.95);
    glEnd();

    ///Parking Road line 3
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.105, -0.3, 1.05);
    glVertex3f (-0.095, -0.3, 1.05);
    glVertex3f (-0.095, -0.3, 1.25);
    glVertex3f (-0.105, -0.3, 1.25);
    glEnd();

    ///Parking Road line 3
    glBegin(GL_QUADS);
    glColor3f (1.0, 1.0, 1.0);
    glVertex3f (-0.105, -0.3, 1.35);
    glVertex3f (-0.095, -0.3, 1.35);
    glVertex3f (-0.095, -0.3, 1.50);
    glVertex3f (-0.105, -0.3, 1.50);
    glEnd();
}

void MosqueRoad()
{

    ///Step
    ///road 1
    glBegin(GL_QUADS);
    glColor3f (1., 1., 1.);
    glVertex3f (.60, -0.3, 0.25);
    glVertex3f (.90, -0.3, 0.25);
    glVertex3f (.90,-0.3, 0.40);
    glVertex3f (.60, -0.3, 0.40);
    glEnd();

    ///road 1
    glBegin(GL_QUADS);
    glColor3f (1., 1., 1.);
    glVertex3f (.70, -0.3, 0.25);
    glVertex3f (.80, -0.3, 0.25);
    glVertex3f (.80,-0.3, 1);
    glVertex3f (.70, -0.3, 1);
    glEnd();

    ///road 2
    glBegin(GL_QUADS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex3f (.10, -0.3, 1.5);
    glVertex3f (.20, -0.3, 1.5);
    glVertex3f (.20, -0.3, 1);
    glVertex3f (.10, -0.3, 1);
    glEnd();

    ///road 2
    glBegin(GL_QUADS);
    glColor3f (1, 1, 1);
    glVertex3f (.20, -0.3, 1.1);
    glVertex3f (.80, -0.3, 1.1);
    glVertex3f (.80, -0.3, 1);
    glVertex3f (.20, -0.3, 1);
    glEnd();

     ///road 3
    glBegin(GL_QUADS);
    glColor3f (1, 1, 1);
    glVertex3f (.10, -0.3, 1.5);
    glVertex3f (.20, -0.3, 1.5);
    glVertex3f (.20, -0.3, 1);
    glVertex3f (.10, -0.3, 1);
    glEnd();
}

void Tree1()
{


    ///Tree right....
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.50, -0.3, -1);
    glVertex3f (-0.50, 0.20, -1);
    glVertex3f (-0.50, 0.20, -.95);
    glVertex3f (-0.50, -0.3, -.95);
    glEnd();
    ///Tree Left....
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.55, -0.3, -1);
    glVertex3f (-0.55, 0.20, -1);
    glVertex3f (-0.55, 0.20, -.95);
    glVertex3f (-0.55, -0.3, -.95);
    glEnd();
    ///Tree front....
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.50, -0.3, -1);
    glVertex3f (-0.55, -0.3, -1);
    glVertex3f (-0.55, 0.20, -1);
    glVertex3f (-0.50, 0.20, -1);
    glEnd();


    ///Tree Top
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.40, .30, -1);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.60, .30, -1);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.50, .45, -1);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();


}
void Tree2()
{


    ///Tree right....
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.50, -0.3, 0.05);
    glVertex3f (-0.50, 0.20, 0.05);
    glVertex3f (-0.50, 0.20, 0.00);
    glVertex3f (-0.50, -0.3, 0.00);
    glEnd();
    ///Tree Left....
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.55, -0.3, 0.05);
    glVertex3f (-0.55, 0.20, 0.05);
    glVertex3f (-0.55, 0.20, 0.00);
    glVertex3f (-0.55, -0.3, 0.00);
    glEnd();
    ///Tree front....
    glBegin(GL_QUADS);
    glColor3f (0.647059, 0.164706, 0.164706);
    glVertex3f (-0.50, -0.3, 0.05);
    glVertex3f (-0.55, -0.3, 0.05);
    glVertex3f (-0.55, 0.20, 0.05);
    glVertex3f (-0.50, 0.20, 0.05);
    glEnd();

    ///Tree Top
    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.40, .30, .05);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.60, .30, .05);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

    glColor3f (0, 1, 0); //first cloud
    glPushMatrix();
    glTranslatef(-.50, .45, .05);
    glutSolidSphere(0.15,36,100);
    glPopMatrix();

}
void Car1()
{

    glColor3f (1, 0, 0);
    glTranslatef(.0,0.8,0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ZERO);
    glBegin(GL_LINE_LOOP);
    glColor3f (1, 0, 0);
    glVertex3f(-1.12,-.48,0.7);
    glVertex3f(-0.86,-.48,0.7);
    glVertex3f(-.74,-0.2,0.7);
    glVertex3f(-.42,-.2,0.7);
    glVertex3f(-0.3,-.48,0.7);
    glVertex3f(.81,-0.48,0.7);
    glVertex3f(.94,-0.2,0.7);
    glVertex3f(1.24,-.2,0.7);
    glVertex3f(1.38,-.48,0.7);
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f (1, 0, 0);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_LINES);
    glColor3f (1, 0, 0);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON); // top filling
    glColor3f (1, 0, 0);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(.52,0.56,0.7);//n
    glEnd();
    glBegin(GL_POLYGON); //back filling
    glColor3f (1, 0, 0);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.14,0.22,0.7);//l
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(0.0,-0.2,0.7);//oo
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,0.5,0.7);//ee
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);
    glVertex3f(0.0,0.5,0.7);//ff
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.12,0.5,0.7);//ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.76,.22,0.7);//m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,-0.7);//bb'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,0.5,-0.7);//ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,-0.7);//ff'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.12,0.5,-0.7);//ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.76,.22,-0.7);//m'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.24,-.2,-0.7);//h'
    glEnd();
    glBegin(GL_POLYGON); // door1 body- rear, near
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON); // door body- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON); // door2 body- near, driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glBegin(GL_POLYGON); // door2 body- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_POLYGON);//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glTranslatef(-.58,-.52,0.7); //translate to 1st tyre
    glColor3f(0.09,0.09,0.09); // tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68,0.0,0.0); //translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0,0.0,-1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68,0.0,0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58,.52,0.7); //translate to origin
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0,0.0,1.40);
    glRotatef(270.0,0.0,1.0,0.0);
    glBegin(GL_POLYGON); //bottom filling
    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.81,-0.48,0.7);//f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-1.12,-.48,0.7);//a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-0.86,-.48,0.7);//b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.74,-0.2,0.7);//c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-.42,-.2,0.7);//d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.94,-0.2,0.7);//g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.38,-.48,0.7);//i
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0); //front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glColor3f(0.0,0.0,1.0);
// transparent objects are placed next ..
    ///glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
//windscreen
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0); //COLOR =WHITE TRANSPARENT
    glVertex3f(0.562,.5,.6);//AAA
    glVertex3f(.562,.5,-.6);//AAA'
    glVertex3f(.76,.22,-.6);//MMM'
    glVertex3f(.76,.22,.6);//MMM
    glEnd();
    glBegin(GL_POLYGON); //rear window
//COLOR =WHITE TRANSPARENT
glColor3f (1, 0, 0);
    glVertex3f(-1.068,0.5,0.6);//pp
    glVertex3f(-1.068,0.5,-0.6);//pp'
    glVertex3f(-1.2,0.22,-0.6);//qq'
    glVertex3f(-1.2,0.22,0.6);//qq
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0);//leftmost window front
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (1, 0, 0); //leftmost window back
    glVertex3f(-0.98,0.5,-0.7);//aa
    glVertex3f(-0.64,0.5,-0.7);//bb
    glVertex3f(-0.64,0.22,-0.7);//cc
    glVertex3f(-1.08,0.22,-0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //middle window front
    glVertex3f(-0.5,0.5,0.7);
    glVertex3f(0.0,0.5,0.7);
    glVertex3f(0.0,0.22,0.7);
    glVertex3f(-0.5,0.22,0.7);
    glEnd();
    glBegin(GL_POLYGON); //middle window back
    glVertex3f(-0.5,0.5,-0.7);
    glVertex3f(0.0,0.5,-0.7);
    glVertex3f(0.0,0.22,-0.7);
    glVertex3f(-0.5,0.22,-0.7);
    glEnd();
    glBegin(GL_POLYGON); //rightmost window front
    glVertex3f(0.12,0.5,0.7);//ii
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.12,0.22,0.7);//ll
    glEnd();
    glBegin(GL_POLYGON); //rightmost window back
    glVertex3f(0.12,0.5,-0.7);//ii'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glEnd();
    glColor3f(1.0,0.0,.0);

}

void Car2()
{

    glColor3f(1,.5,0);
    glTranslatef(.0,0.8,0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ZERO);
    glBegin(GL_LINE_LOOP);
    glColor3f(1,.5,0);
    glVertex3f(-1.12,-.48,0.7);
    glVertex3f(-0.86,-.48,0.7);
    glVertex3f(-.74,-0.2,0.7);
    glVertex3f(-.42,-.2,0.7);
    glVertex3f(-0.3,-.48,0.7);
    glVertex3f(.81,-0.48,0.7);
    glVertex3f(.94,-0.2,0.7);
    glVertex3f(1.24,-.2,0.7);
    glVertex3f(1.38,-.48,0.7);
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glColor3f(1,.5,0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1,.5,0);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON); // top filling
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(.52,0.56,0.7);//n
    glEnd();
    glBegin(GL_POLYGON); //back filling
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.14,0.22,0.7);//l
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(0.0,-0.2,0.7);//oo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,0.5,0.7);//ee
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,0.7);//ff
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.12,0.5,0.7);//ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.76,.22,0.7);//m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,-0.7);//bb'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,0.5,-0.7);//ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,-0.7);//ff'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.12,0.5,-0.7);//ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.76,.22,-0.7);//m'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.24,-.2,-0.7);//h'
    glEnd();
    glBegin(GL_POLYGON); // door1 body- rear, near
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON); // door body- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON); // door2 body- near, driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glBegin(GL_POLYGON); // door2 body- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_POLYGON);//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glTranslatef(-.58,-.52,0.7); //translate to 1st tyre
    glColor3f(0.09,0.09,0.09); // tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68,0.0,0.0); //translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0,0.0,-1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68,0.0,0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58,.52,0.7); //translate to origin
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0,0.0,1.40);
    glRotatef(270.0,0.0,1.0,0.0);
    glBegin(GL_POLYGON); //bottom filling
    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.81,-0.48,0.7);//f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-1.12,-.48,0.7);//a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-0.86,-.48,0.7);//b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.74,-0.2,0.7);//c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-.42,-.2,0.7);//d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.94,-0.2,0.7);//g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.38,-.48,0.7);//i
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();


    glBegin(GL_POLYGON); //front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glColor3f(0.0,0.0,1.0);
// transparent objects are placed next ..
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
//windscreen
    glBegin(GL_POLYGON);
    glColor4f(0.0,0.0,0.0,0.7); //COLOR =WHITE TRANSPARENT
    glVertex3f(0.562,.5,.6);//AAA
    glVertex3f(.562,.5,-.6);//AAA'
    glVertex3f(.76,.22,-.6);//MMM'
    glVertex3f(.76,.22,.6);//MMM
    glEnd();
    glBegin(GL_POLYGON); //rear window
//COLOR =WHITE TRANSPARENT
    glVertex3f(-1.068,0.5,0.6);//pp
    glVertex3f(-1.068,0.5,-0.6);//pp'
    glVertex3f(-1.2,0.22,-0.6);//qq'
    glVertex3f(-1.2,0.22,0.6);//qq
    glEnd();
    glBegin(GL_POLYGON); //leftmost window front
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //leftmost window back
    glVertex3f(-0.98,0.5,-0.7);//aa
    glVertex3f(-0.64,0.5,-0.7);//bb
    glVertex3f(-0.64,0.22,-0.7);//cc
    glVertex3f(-1.08,0.22,-0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //middle window front
    glVertex3f(-0.5,0.5,0.7);
    glVertex3f(0.0,0.5,0.7);
    glVertex3f(0.0,0.22,0.7);
    glVertex3f(-0.5,0.22,0.7);
    glEnd();
    glBegin(GL_POLYGON); //middle window back
    glVertex3f(-0.5,0.5,-0.7);
    glVertex3f(0.0,0.5,-0.7);
    glVertex3f(0.0,0.22,-0.7);
    glVertex3f(-0.5,0.22,-0.7);
    glEnd();
    glBegin(GL_POLYGON); //rightmost window front
    glVertex3f(0.12,0.5,0.7);//ii
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.12,0.22,0.7);//ll
    glEnd();
    glBegin(GL_POLYGON); //rightmost window back
    glVertex3f(0.12,0.5,-0.7);//ii'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glEnd();
    glColor3f(0.0,0.0,1.0);

}

void Car3()
{
    glColor3f(0.0,0.0,1.0);
    glTranslatef(.0,0.8,0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ZERO);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,0.7);
    glVertex3f(-0.86,-.48,0.7);
    glVertex3f(-.74,-0.2,0.7);
    glVertex3f(-.42,-.2,0.7);
    glVertex3f(-0.3,-.48,0.7);
    glVertex3f(.81,-0.48,0.7);
    glVertex3f(.94,-0.2,0.7);
    glVertex3f(1.24,-.2,0.7);
    glVertex3f(1.38,-.48,0.7);
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON); // top filling
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(.52,0.56,0.7);//n
    glEnd();
    glBegin(GL_POLYGON); //back filling
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.14,0.22,0.7);//l
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(0.0,-0.2,0.7);//oo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,0.5,0.7);//ee
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,0.7);//ff
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.12,0.5,0.7);//ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.76,.22,0.7);//m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,-0.7);//bb'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,0.5,-0.7);//ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,-0.7);//ff'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.12,0.5,-0.7);//ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.76,.22,-0.7);//m'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.24,-.2,-0.7);//h'
    glEnd();
    glBegin(GL_POLYGON); // door1 body- rear, near
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON); // door body- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON); // door2 body- near, driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glBegin(GL_POLYGON); // door2 body- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_POLYGON);//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glTranslatef(-.58,-.52,0.7); //translate to 1st tyre
    glColor3f(0.09,0.09,0.09); // tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68,0.0,0.0); //translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0,0.0,-1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68,0.0,0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58,.52,0.7); //translate to origin
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0,0.0,1.40);
    glRotatef(270.0,0.0,1.0,0.0);
    glBegin(GL_POLYGON); //bottom filling
    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.81,-0.48,0.7);//f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-1.12,-.48,0.7);//a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-0.86,-.48,0.7);//b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.74,-0.2,0.7);//c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-.42,-.2,0.7);//d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.94,-0.2,0.7);//g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.38,-.48,0.7);//i
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();


    glBegin(GL_POLYGON); //front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glColor3f(0.0,0.0,1.0);
// transparent objects are placed next ..
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
//windscreen
    glBegin(GL_POLYGON);
    glColor4f(0.0,0.0,0.0,0.7); //COLOR =WHITE TRANSPARENT
    glVertex3f(0.562,.5,.6);//AAA
    glVertex3f(.562,.5,-.6);//AAA'
    glVertex3f(.76,.22,-.6);//MMM'
    glVertex3f(.76,.22,.6);//MMM
    glEnd();
    glBegin(GL_POLYGON); //rear window
//COLOR =WHITE TRANSPARENT
    glVertex3f(-1.068,0.5,0.6);//pp
    glVertex3f(-1.068,0.5,-0.6);//pp'
    glVertex3f(-1.2,0.22,-0.6);//qq'
    glVertex3f(-1.2,0.22,0.6);//qq
    glEnd();
    glBegin(GL_POLYGON); //leftmost window front
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //leftmost window back
    glVertex3f(-0.98,0.5,-0.7);//aa
    glVertex3f(-0.64,0.5,-0.7);//bb
    glVertex3f(-0.64,0.22,-0.7);//cc
    glVertex3f(-1.08,0.22,-0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //middle window front
    glVertex3f(-0.5,0.5,0.7);
    glVertex3f(0.0,0.5,0.7);
    glVertex3f(0.0,0.22,0.7);
    glVertex3f(-0.5,0.22,0.7);
    glEnd();
    glBegin(GL_POLYGON); //middle window back
    glVertex3f(-0.5,0.5,-0.7);
    glVertex3f(0.0,0.5,-0.7);
    glVertex3f(0.0,0.22,-0.7);
    glVertex3f(-0.5,0.22,-0.7);
    glEnd();
    glBegin(GL_POLYGON); //rightmost window front
    glVertex3f(0.12,0.5,0.7);//ii
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.12,0.22,0.7);//ll
    glEnd();
    glBegin(GL_POLYGON); //rightmost window back
    glVertex3f(0.12,0.5,-0.7);//ii'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glEnd();
    glColor3f(0.0,0.0,1.0);

}

void Car4()
{

    glTranslatef(.0,0.8,0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ZERO);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,0.7);
    glVertex3f(-0.86,-.48,0.7);
    glVertex3f(-.74,-0.2,0.7);
    glVertex3f(-.42,-.2,0.7);
    glVertex3f(-0.3,-.48,0.7);
    glVertex3f(.81,-0.48,0.7);
    glVertex3f(.94,-0.2,0.7);
    glVertex3f(1.24,-.2,0.7);
    glVertex3f(1.38,-.48,0.7);
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON); // top filling
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(.52,0.56,0.7);//n
    glEnd();
    glBegin(GL_POLYGON); //back filling
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.14,0.22,0.7);//l
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(0.0,-0.2,0.7);//oo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,0.5,0.7);//ee
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,0.7);//ff
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.12,0.5,0.7);//ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.76,.22,0.7);//m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,-0.7);//bb'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,0.5,-0.7);//ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,-0.7);//ff'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.12,0.5,-0.7);//ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.76,.22,-0.7);//m'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.24,-.2,-0.7);//h'
    glEnd();
    glBegin(GL_POLYGON); // door1 body- rear, near
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON); // door body- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON); // door2 body- near, driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glBegin(GL_POLYGON); // door2 body- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_POLYGON);//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glTranslatef(-.58,-.52,0.7); //translate to 1st tyre
    glColor3f(0.09,0.09,0.09); // tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68,0.0,0.0); //translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0,0.0,-1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68,0.0,0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58,.52,0.7); //translate to origin
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0,0.0,1.40);
    glRotatef(270.0,0.0,1.0,0.0);
    glBegin(GL_POLYGON); //bottom filling
    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.81,-0.48,0.7);//f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-1.12,-.48,0.7);//a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-0.86,-.48,0.7);//b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.74,-0.2,0.7);//c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-.42,-.2,0.7);//d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.94,-0.2,0.7);//g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.38,-.48,0.7);//i
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glBegin(GL_POLYGON); //front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glColor3f(0.0,0.0,1.0);
// transparent objects are placed next ..
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
//windscreen
    glBegin(GL_POLYGON);
    glColor4f(1.0,1.0,1.0,1.0); //COLOR =WHITE TRANSPARENT
    glVertex3f(0.562,.5,.6);//AAA
    glVertex3f(.562,.5,-.6);//AAA'
    glVertex3f(.76,.22,-.6);//MMM'
    glVertex3f(.76,.22,.6);//MMM
    glEnd();
    glBegin(GL_POLYGON); //rear window
//COLOR =WHITE TRANSPARENT
    glVertex3f(-1.068,0.5,0.6);//pp
    glVertex3f(-1.068,0.5,-0.6);//pp'
    glVertex3f(-1.2,0.22,-0.6);//qq'
    glVertex3f(-1.2,0.22,0.6);//qq
    glEnd();
    glBegin(GL_POLYGON); //leftmost window front
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //leftmost window back
    glVertex3f(-0.98,0.5,-0.7);//aa
    glVertex3f(-0.64,0.5,-0.7);//bb
    glVertex3f(-0.64,0.22,-0.7);//cc
    glVertex3f(-1.08,0.22,-0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //middle window front
    glVertex3f(-0.5,0.5,0.7);
    glVertex3f(0.0,0.5,0.7);
    glVertex3f(0.0,0.22,0.7);
    glVertex3f(-0.5,0.22,0.7);
    glEnd();
    glBegin(GL_POLYGON); //middle window back
    glVertex3f(-0.5,0.5,-0.7);
    glVertex3f(0.0,0.5,-0.7);
    glVertex3f(0.0,0.22,-0.7);
    glVertex3f(-0.5,0.22,-0.7);
    glEnd();
    glBegin(GL_POLYGON); //rightmost window front
    glVertex3f(0.12,0.5,0.7);//ii
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.12,0.22,0.7);//ll
    glEnd();
    glBegin(GL_POLYGON); //rightmost window back
    glVertex3f(0.12,0.5,-0.7);//ii'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glEnd();
    glColor3f(1.0,1.0,1.0);

}

void Car7()
{

    glTranslatef(.0,0.8,0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ZERO);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,0.7);
    glVertex3f(-0.86,-.48,0.7);
    glVertex3f(-.74,-0.2,0.7);
    glVertex3f(-.42,-.2,0.7);
    glVertex3f(-0.3,-.48,0.7);
    glVertex3f(.81,-0.48,0.7);
    glVertex3f(.94,-0.2,0.7);
    glVertex3f(1.24,-.2,0.7);
    glVertex3f(1.38,-.48,0.7);
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON); // top filling
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(.52,0.56,0.7);//n
    glEnd();
    glBegin(GL_POLYGON); //back filling
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.14,0.22,0.7);//l
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(0.0,-0.2,0.7);//oo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,0.5,0.7);//ee
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,0.7);//ff
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.12,0.5,0.7);//ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.76,.22,0.7);//m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,-0.7);//bb'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,0.5,-0.7);//ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,-0.7);//ff'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.12,0.5,-0.7);//ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.76,.22,-0.7);//m'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.24,-.2,-0.7);//h'
    glEnd();
    glBegin(GL_POLYGON); // door1 body- rear, near
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON); // door body- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON); // door2 body- near, driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glBegin(GL_POLYGON); // door2 body- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_POLYGON);//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glTranslatef(-.58,-.52,0.7); //translate to 1st tyre
    glColor3f(0.09,0.09,0.09); // tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68,0.0,0.0); //translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0,0.0,-1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68,0.0,0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58,.52,0.7); //translate to origin
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0,0.0,1.40);
    glRotatef(270.0,0.0,1.0,0.0);
    glBegin(GL_POLYGON); //bottom filling
    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.81,-0.48,0.7);//f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-1.12,-.48,0.7);//a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-0.86,-.48,0.7);//b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.74,-0.2,0.7);//c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-.42,-.2,0.7);//d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.94,-0.2,0.7);//g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.38,-.48,0.7);//i
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();


    glBegin(GL_POLYGON); //front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glColor3f(0.0,0.0,1.0);
// transparent objects are placed next ..
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
//windscreen
    glBegin(GL_POLYGON);
    glColor4f(1.0,0.0,0.0,0.7); //COLOR =WHITE TRANSPARENT
    glVertex3f(0.562,.5,.6);//AAA
    glVertex3f(.562,.5,-.6);//AAA'
    glVertex3f(.76,.22,-.6);//MMM'
    glVertex3f(.76,.22,.6);//MMM
    glEnd();
    glBegin(GL_POLYGON); //rear window
//COLOR =WHITE TRANSPARENT
    glVertex3f(-1.068,0.5,0.6);//pp
    glVertex3f(-1.068,0.5,-0.6);//pp'
    glVertex3f(-1.2,0.22,-0.6);//qq'
    glVertex3f(-1.2,0.22,0.6);//qq
    glEnd();
    glBegin(GL_POLYGON); //leftmost window front
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //leftmost window back
    glVertex3f(-0.98,0.5,-0.7);//aa
    glVertex3f(-0.64,0.5,-0.7);//bb
    glVertex3f(-0.64,0.22,-0.7);//cc
    glVertex3f(-1.08,0.22,-0.7);//dd
    glEnd();
    glBegin(GL_POLYGON); //middle window front
    glVertex3f(-0.5,0.5,0.7);
    glVertex3f(0.0,0.5,0.7);
    glVertex3f(0.0,0.22,0.7);
    glVertex3f(-0.5,0.22,0.7);
    glEnd();
    glBegin(GL_POLYGON); //middle window back
    glVertex3f(-0.5,0.5,-0.7);
    glVertex3f(0.0,0.5,-0.7);
    glVertex3f(0.0,0.22,-0.7);
    glVertex3f(-0.5,0.22,-0.7);
    glEnd();
    glBegin(GL_POLYGON); //rightmost window front
    glVertex3f(0.12,0.5,0.7);//ii
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.12,0.22,0.7);//ll
    glEnd();
    glBegin(GL_POLYGON); //rightmost window back
    glVertex3f(0.12,0.5,-0.7);//ii'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glEnd();
    glColor3f(0.0,0.0,1.0);

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
    ///POND
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Pond();
    glPopMatrix();
    ///FLOOR
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Floor();
    glPopMatrix();
    ///CAR4_ANIMATION_BACKROAD
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(-31+s ,-4, -31);
    glRotatef(0.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car1();
    glPopMatrix();
    ///CAR4_ANIMATION_BACKROAD
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(-31+w ,-4, -27);
    glRotatef(180.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car4();
    glPopMatrix();
    ///BOUNDRYBACK
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    BoundaryBack();
    glPopMatrix();
    ///TREE2
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(1,0,-1);
    glRotatef(0,0,0,0);
    Tree2();
    glPopMatrix();
    ///BOUNDARYRIGHT
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    BoundaryRight();
    glPopMatrix();
    ///PARKING
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Parking();
    glPopMatrix();
    ///CAR4
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(1.5,-4.0,-5);
    glRotatef(90.0,0,1,0);
    Car4();
    glPopMatrix();
    ///CAR1
    glPushMatrix();
    glScalef(.07+xx,.07+yy,.07+zz);
    glTranslatef(-2,-4,-5);
    glRotatef(90.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car1();
    glPopMatrix();
    ///CAR7
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(-2.2 ,-4, 3+ n);
    glRotatef(90.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car7();
    glPopMatrix();
    ///MINAR
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Minar();
    glPopMatrix();
    ///MOSQUE
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Mosque();
    glPopMatrix();
    ///CAR2
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(1+xxx ,-4, -.5-jjj);
    glRotatef(00.0,0,1,0);
    glRotatef((GLfloat)xangle,1,0,0);
    glRotatef((GLfloat)yangle,0,1,0);
    glRotatef((GLfloat)zangle,0,0,1);
    glColor3f(0.419,0.556,0.137);
    Car2();
    glPopMatrix();
    ///CAR3
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(1.5,-4,3);
    glRotatef(90.0,0,1,0);
    Car3();
    glPopMatrix();
    ///BOUNDARYLEFT
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    BoundaryLeft();
    glPopMatrix();
    ///WUDUPLACE
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    glTranslatef(.3,0,.1);
    glRotatef(0,0,0,0);
    WuduPlace();
    glPopMatrix();
    ///TREE1
    glPushMatrix();
    Tree1();
    glPopMatrix();
    ///DOOR
    glPushMatrix();
    glTranslatef(0-g ,0, 0);
    Door();
    glPopMatrix();
    ///MOSQUE_ROAD
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    MosqueRoad();
    glPopMatrix();
    ///BOUNDARYFRONT
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    BoundaryFront();
    glPopMatrix();
    ///CAR3_ANIMATION_LEFTROAD
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(-31 ,-4, 5+ q);
    glRotatef(90.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car3();
    glPopMatrix();
    ///CAR4_ANIMATION_FRONTROAD
    glPushMatrix();
    glScalef(.07,.07,.07);
    glTranslatef(-31+w ,-4, 31);
    glRotatef(180.0,0,1,0);
    glColor3f(0.419,0.556,0.137);
    Car4();
    glPopMatrix();
    ///SUN
    glPushMatrix();
    glColor3f(0.419,0.556,0.137);
    Sun();
    glPopMatrix();
    ///CLOUD1
    glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-1.5+m ,-0.9,0);
    glRotatef(0.0,0,0,0);
    cloud1();
    glPopMatrix();
    ///CLOUD2
    glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-1.5+t ,-0.9,0);
    glRotatef(0.0,0,0,0);
    cloud2();
    glPopMatrix();
    ///CLOUD3
    glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-1.5+e ,-0.9,0);
    glRotatef(0.0,0,0,0);
    cloud3();
    glPopMatrix();




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
