double two_cricle_intersection_area(double r,double R,double d){
	if(R < r){
	    swap(R,r);
	}
	if(d>R+r) return 0;
	if(d + r <= R) return acos(-1.0)*r*r;
	return 	r*r*acos((d*d + r*r - R*R)/(2*d*r))+
			R*R*acos((d*d + R*R - r*r)/(2*d*R))+
			0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));
}