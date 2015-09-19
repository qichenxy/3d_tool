#ifndef GLVISUALIZATION_H
#define GLVISUALIZATION_H

#include <QGLWidget>
#include <vector>
class VPoint
{
public:
    VPoint()
    {
        x=0;
        y=0;
        z=0;
    }

    VPoint(float xx, float yy, float zz) : x(xx), y(yy), z(zz)
    {
    }

    float x;
    float y;
    float z;
};

typedef std::vector<VPoint>   VisualPointCloud;
typedef std::vector<VPoint>   VisualRealTrajectory;
typedef std::vector<VPoint>   VisualPlannedTrajectory;
typedef std::vector<VPoint>   VisualGridMap;


class GlVisualization
{
public:
    GlVisualization();

    void drawFrame()
    {
        glPointSize(5);
        glColor3f(0.3, 0.8, 0.6);
        glBegin(GL_POINT);
        glVertex3f(0, 0, 0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0, 0, 0);
        glVertex3f(1.0, 0, 0);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1);
        glEnd();
    }


    void drawGrid(int range)
    {
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        for(int i=-range; i<range; i++)
        {
            glVertex3f(-range, i,0);
            glVertex3f(range, i,0);

            glVertex3f(i, -range,0);
            glVertex3f(i, range,0);

        }
        glEnd();
    }
protected:

private:
    VisualPointCloud points_;
    VisualRealTrajectory real_trajectory_;
    VisualPlannedTrajectory planned_trajectory;
    VisualGridMap grid_map_;
};

#endif // GLVISUALIZATION_H
