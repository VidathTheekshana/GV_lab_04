#include <GLUT/glut.h>
static void drawCube(void) {
    // Front (Red)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4f, -0.2f,  0.0f);
        glVertex3f(-0.4f,  0.2f,  0.0f);
        glVertex3f( 0.0f,  0.2f,  0.0f);
        glVertex3f( 0.0f, -0.2f,  0.0f);
    glEnd();

    // Back (Green)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.2f,  0.0f, -0.4f);
        glVertex3f(-0.2f,  0.4f, -0.4f);
        glVertex3f( 0.2f,  0.4f, -0.4f);
        glVertex3f( 0.2f,  0.0f, -0.4f);
    glEnd();

    // Left (Blue)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4f, -0.2f,  0.0f);
        glVertex3f(-0.4f,  0.2f,  0.0f);
        glVertex3f(-0.2f,  0.4f, -0.4f);
        glVertex3f(-0.2f,  0.0f, -0.4f);
    glEnd();

    // Right (Blue)
    glBegin(GL_POLYGON);
        glVertex3f( 0.0f, -0.2f,  0.0f);
        glVertex3f( 0.0f,  0.2f,  0.0f);
        glVertex3f( 0.2f,  0.4f, -0.4f);
        glVertex3f( 0.2f,  0.0f, -0.4f);
    glEnd();

    // Top (White)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4f,  0.2f,  0.0f);   // A
        glVertex3f( 0.0f,  0.2f,  0.0f);   // B
        glVertex3f( 0.2f,  0.4f, -0.4f);   // C
        glVertex3f(-0.2f,  0.4f, -0.4f);   // D
    glEnd();

    // Bottom (Yellow)
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4f, -0.2f,  0.0f);
        glVertex3f( 0.0f, -0.2f,  0.0f);
        glVertex3f( 0.2f,  0.0f, -0.4f);
        glVertex3f(-0.2f,  0.0f, -0.4f);
    glEnd();
}


static void drawPyramidOnCubeTop(void) {
   
    const GLfloat A[3] = {-0.4f, 0.2f,  0.0f};
    const GLfloat B[3] = { 0.0f, 0.2f,  0.0f};
    const GLfloat C[3] = { 0.2f, 0.4f, -0.4f};
    const GLfloat D[3] = {-0.2f, 0.4f, -0.4f};

    const GLfloat apex[3] = {-0.1f, 0.7f, -0.2f};

    // A–B side
    glColor3f(1.0f, 0.4f, 0.0f); // orange
    glBegin(GL_TRIANGLES);
        glVertex3fv(apex); glVertex3fv(A); glVertex3fv(B);
    glEnd();

    // B–C side
    glColor3f(0.0f, 0.8f, 0.0f); // greenish
    glBegin(GL_TRIANGLES);
        glVertex3fv(apex); glVertex3fv(B); glVertex3fv(C);
    glEnd();

    // C–D side
    glColor3f(0.2f, 0.4f, 1.0f); // blueish
    glBegin(GL_TRIANGLES);
        glVertex3fv(apex); glVertex3fv(C); glVertex3fv(D);
    glEnd();

    // D–A side
    glColor3f(1.0f, 1.0f, 0.0f); // yellow
    glBegin(GL_TRIANGLES);
        glVertex3fv(apex); glVertex3fv(D); glVertex3fv(A);
    glEnd();
}


static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawCube();
    drawPyramidOnCubeTop();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    // Add depth buffer for correct overlap
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cube of I23398184");

    // background color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // enable depth test
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
