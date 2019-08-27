ll solve(ll a,ll b,ll c,ll xmin,ll xmax,ll ymin,ll ymax){
	//Ax + By = C ; number of solution for x in [xmin,xmax] y in [ymin,ymax]
    ll x0,Y0,ans;
    ll g=egcd(abs(a),abs(b),x0,Y0);
    if(a==0 && b==0)
    {
        if(c!=0)ans=0;
        else
        {
            ans=(xmax-xmin+1)*(ymax-ymin+1);
            //ans should be infinity
        }
    }else if(c%g!=0)ans=0;
    else
    {
        if(a<0)x0*=-1;
        if(b<0)Y0*=-1;
        x0*=(c/g),Y0*=(c/g);

        if(a==0)
        {
            if(Y0>=ymin && Y0<=ymax)ans=(xmax-xmin+1);
            else ans=0;
        }else if(b==0)
        {
            if(x0>=xmin && x0<=xmax)ans=(ymax-ymin+1);
            else ans=0;
        }else
        {
            ll k=b>0?ceil(g*(xmin-x0+0.0)/b):floor(g*(xmin-x0+0.0)/b);
            ll xs1=x0+(b/g)*k;
            k=b>0?floor((g*(xmax-x0+0.0))/b):ceil((g*(xmax-x0+0.0))/b);
            //note that integer arethmetic could not find floor for negative value
            ll xe1=x0+(b/g)*k;
            k=a>0?floor(g*(Y0-ymin+0.0)/a):ceil(g*(Y0-ymin+0.0)/a);
            ll ys=Y0-(a/g)*k;
            ll xe2=(c-b*ys)/a;
            k=a>0?ceil(g*(Y0-ymax+0.0)/a):floor(g*(Y0-ymax+0.0)/a);
            ll ye=Y0-(a/g)*k;
            ll xs2=(c-b*ye)/a;
            if(xs2>xe2)swap(xs2,xe2);
            if(xs1>xs2)
            {
                swap(xs1,xs2);
                swap(xe1,xe2);
            }
            if(xs1>xe1  || ys>ye)ans=0;
            else if(xs2>xe1)ans=0;
            else ans=(min(xe1,xe2)-xs2)/(abs(b)/g) + 1;
        }
    }
    return abs(ans);
}

