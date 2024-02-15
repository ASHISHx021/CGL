#include <GL/glut.h>

// Function to draw a circle using Midpoint algorithm
void drawCircle(int radius) {
    int x = 0, y = radius;
    int decision = 1 - radius; // Initial decision factor

    glBegin(GL_POINTS);
    while (x <= y) {
        // Plot the points in all eight octants
        glVertex2i(x, y);
        glVertex2i(-x, y);
        glVertex2i(x, -y);
        glVertex2i(-x, -y);
        glVertex2i(y, x);
        glVertex2i(-y, x);
        glVertex2i(y, -x);
        glVertex2i(-y, -x);

        // Update decision factor and next pixel coordinates
        if (decision < 0) {
            decision += 2 * x + 3;
        } else {
            decision += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
}

// Function to display rendering
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glPointSize(2.0); // Set point size
    glLoadIdentity();

    drawCircle(100); // Change the radius as per your requirement

    glFlush();
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
    gluOrtho2D(-200, 200, -200, 200); // Set coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400); // Set window size
    glutCreateWindow("Circle Drawing using Midpoint Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
