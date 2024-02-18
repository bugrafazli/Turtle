#include <GLUT/glut.h>
#include <cmath>

//mac uzerinde yaptim.

float x, y, t;
int tortuepatte[] = {-2, 6, 22, 30};

void lapin() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 210 + 40);
    glVertex2i(60, 210 + 40);
    glVertex2i(70, 220 + 40);
    glVertex2i(70, 230 + 40);
    glVertex2i(60, 240 + 40);
    glVertex2i(50, 240 + 40);
    glVertex2i(40, 230 + 40);
    glVertex2i(40, 220 + 40);
    glEnd();

    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++) {
        x = 78 + 9 * cos(t);
        y = 273 + 9 * sin(t);
        glVertex2f(70, 260);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2i(78, 273);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++) {
        x = 74 + 4 * cos(t);
        y = 295 + 4 * sin(t);
        glVertex2f(70, 270);
        glVertex2f(x, y);
    }
    glEnd();
}

void tortue() {
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++) {
        x = 50 + 22 * cos(t);
        y = 180 + 22 * sin(t);
        glVertex2f(50, 180);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(28, 180);
    glVertex2i(72, 180);
    glVertex2i(72, 158);
    glVertex2i(28, 158);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (t = 0; t <= 360; t++) {
        x = 82 + 7 * cos(t);
        y = 184 + 7 * sin(t);
        glVertex2f(72, 182);
        glVertex2f(x, y);
    }
    glEnd();

    for (int i = 0; i < 4; i++) {
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_POLYGON);
        glVertex2i(32 + tortuepatte[i], 170);
        glVertex2i(38 + tortuepatte[i], 170);
        glVertex2i(37 + tortuepatte[i], 180);
        glVertex2i(33 + tortuepatte[i], 180);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.5,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(0,425);
    glVertex2i(1000,425);
    glVertex2i(1000,50);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2i(100,50);
    glVertex2i(100,425);
    glEnd();
    lapin();
    tortue();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.1, 0.8, 0.1, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("Lapin et Tortue");
    glutPositionWindow(60, 75);
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
