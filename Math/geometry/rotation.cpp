//Not tested
typedef pair<double,double> point;
point rot(point a,double ang){//rotate the point respect to origin by ang rad
    return {a.first*cos(ang) - a.second*sin(ang) , a.first*sin(ang) + a.second*cos(ang) };
}
3D
struct P{
    double x,y,z;
};
P rotX(P a,double ang){//rotate on YZ plane,counterclockwise
    return {a.x,a.y*cos(ang)-a.z*sin(ang),a.y*sin(ang)+a.z*cos(ang)};
}
P rotY(P a,double ang){//rotate on ZX plane,counterclockwise
    return {a.x*cos(ang) + a.z*sin(ang),a.y,-a.x*sin(ang) + a.z*cos(ang)};
}
P rotZ(P a,double ang){//rotate on XY plane,counterclockwise
    return {a.x*cos(ang) - a.y*sin(ang) , a.x*sin(ang) + a.y*cos(ang) , a.z};
}
inline double SQ(double a){return a*a;}
P rot(P a,P u,double ang){//u is the unit vector perpendicular (up) to rotation plane, rotation will happen counterclockwise
    double cs=1 - cos(ang);
    return {
        a.x * (cos(ang) + SQ(u.x) * cs)         + a.y * (u.x * u.y * cs - u.z * sin(ang))   + a.z * (u.x * u.z * cs + u.y * sin(ang)),
        a.x * (u.y * u.x * cs + u.z * sin(ang)) + a.y * (cos(ang) + SQ(u.y) * cs)           + a.z * (u.y * u.z * cs - u.x * sin(ang)),
        a.x * (u.z * u.x * cs - u.y * sin(ang)) + a.y * (u.z * u.y * cs + u.x * sin(ang))   + a.z * (cos(ang) + SQ(u.z)*cs)
    };
}
