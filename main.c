
#include <GLUT/glut.h>
#include <stdlib.h>

// Activity 1 : createCube()
void createCube(void) {
 
    glClear(GL_COLOR_BUFFER_BIT);

   

    // Back (Green) 
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.2f,  0.0f, -0.4f); // bottom left
        glVertex3f(-0.2f,  0.4f, -0.4f); // top left
        glVertex3f( 0.2f,  0.4f, -0.4f); // top right
        glVertex3f( 0.2f,  0.0f, -0.4f); // bottom right
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
        glVertex3f(-0.4f,  0.2f,  0.0f);
        glVertex3f( 0.0f,  0.2f,  0.0f);
        glVertex3f( 0.2f,  0.4f, -0.4f);
        glVertex3f(-0.2f,  0.4f, -0.4f);
    glEnd();

    // Bottom (Yellow)
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4f, -0.2f,  0.0f);
        glVertex3f( 0.0f, -0.2f,  0.0f);
        glVertex3f( 0.2f,  0.0f, -0.4f);
        glVertex3f(-0.2f,  0.0f, -0.4f);
    glEnd();

     // Front (Red) 
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4f, -0.2f,  0.0f); // bottom left
        glVertex3f(-0.4f,  0.2f,  0.0f); // top left
        glVertex3f( 0.0f,  0.2f,  0.0f); // top right
        glVertex3f( 0.0f, -0.2f,  0.0f); // bottom right
    glEnd();

    // e) flush immediately
    glFlush();
}

int main(int argc, char** argv) {
 glutInit(&argc, argv); // Initialize GLUT and process command-line arguments
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Set display mode with RGB colorand single buffer
 glutInitWindowPosition(100, 100);// Set window position (upper-left corner at200, 200)
 glutInitWindowSize(400, 400); // Set window size (500x500 pixels)
 glutCreateWindow("Cube of I23398184"); // Create window with title
 glClearColor(0.0, 0.0, 0.0, 1.0); // Set the clear color (background color) toblack
 glutDisplayFunc(createCube); // Register display callback function
 glutMainLoop(); // Enter the GLUT main loop
 return 0;
}



