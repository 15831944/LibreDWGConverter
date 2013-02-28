#ifndef __BUILDER_H_
#define __BUILDER_H_

#include <fstream>

#include "eltypes.h"

namespace converter {
    class Builder 
    {  
    protected:
        std::fstream *out;
        char *filename;

    public:
        Builder(const char*, const char*);
        virtual ~Builder();
        
        virtual void open_header() {}
        virtual void close_header() {}
        
        virtual void add_line_segment(Vector p1, Vector p2, Vector extrusion, 
                                      Double thickness) {}
        
        virtual void add_line(Vector point, Vector vector) {}
        
        virtual void add_arc(Vector center, Double radius, Double start_angle,
                             Double end_angle, Vector extrusion, Double thickness) {}

        virtual void add_circle(Vector center, Double radius, Vector extrusion,
                                Double thickness) {}

        virtual void add_ellipse(Vector center, Vector sm_axis, Double axis_ratio, 
                                 Double start_angle, Double end_angle, 
                                 Vector extrusion) {}
    };
}

#endif