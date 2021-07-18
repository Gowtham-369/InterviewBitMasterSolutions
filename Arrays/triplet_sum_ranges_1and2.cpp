int Solution::solve(vector<string> &A) {
    
    int n = A.size();
    vector<double> v(n);
    
    for(int i=0; i<n; i++){
        v[i] = stof(A[i]);
    }
    double a=v[0],b=v[1],c=v[2];
    double sum = a+b+c;
    if(sum>1.0 && sum < 2.0){
            return 1;
    }
    for(int i=3; i<n; i++){
        sum = a+b+c;
        if(sum>1.0 && sum < 2.0){
            return 1;
        }
        else if(sum >= 2.0){
            
            if(a>b && a>c){
                sum -= a;
                a = v[i];
            }
            else if(b>c){
                sum -= b;
                b = v[i];
            }
            else{
                sum -= c;
                c = v[i];
            }
            
        }
        else{
            //sum <= 1
            
            if(a<c && a<b){
                sum -= a;
                a = v[i];
            }
            else if(b<c){
                sum -= b;
                b = v[i];
            }
            else{
                sum -= c;
                c = v[i];
            }
            
        }
    }
    sum = a+b+c;
    if(sum>1.0 && sum < 2.0){
        return 1;
    }
    return 0;
    /*
    //Solution approacch 2
    vector<double> a,b,c;
    for(int i=0; i<n; i++){
        if(0.0<v[i] && 3*v[i]<(double)2){
            a.push_back(v[i]);
        }
        else if((double)2<=3*v[i] && v[i]<=(double)1){
            b.push_back(v[i]);
        }
        else if(v[i]>(double)1 && v[i]<(double)2){
            c.push_back(v[i]);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    //case if
    // A A A
    int a_size = (int)a.size();
    int b_size = b.size();
    int c_size = c.size();
    if(a_size>=3){
        double x = a[a_size-1]+a[a_size-2]+a[a_size-3];
        if(x>1.0 && x<2.0){
            return 1;
        }
    }
    // A A B
    if(a_size>=2){
        //check for underflow case
        double x = a[a_size-1]+a[a_size-2];
        double sum;
        for(int i=0; i<b_size; i++){
            sum = x+b[i];
            if(sum >1.0 && sum < 2.0){
                return 1;
            }
        }
    }
    // A A C
    if(a_size >= 2 && c.size()>0){
        //check for overflow case
        double x = a[0]+a[1]+c[0];
        if(x>1.0 && x<2.0){
            return 1;
        }
    }
    // A B B
    if(b_size>=2 && a_size>0){
        double x = a[0]+b[0]+b[1];
        if(x>1.0 && x<2.0){
            return 1;
        }
    }
    // A B C
    if(a_size >0 && b_size>0 && c_size>0){
        double x = a[0]+b[0]+c[0];
        if(x>1.0 && x<2.0){
            return 1;
        }
    }
    return 0;
    */
    
}