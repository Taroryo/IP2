#include <stdio.h>

struct Point2D
{
    double x;
    double y;
};
const int N = 5;
double spline(const Point2D pnt[], const double x)
{
	int idx = -1, k;
	double h[N-1], b[N-1], d[N-1], g[N-1], u[N-1], r[N];

	int i;
	for (i=1; i<N-1 && idx<0; i++) {
		if (x < pnt[i].x )
			idx = i - 1;
	}
	
	if (idx < 0)
		idx = N-2;
	
	for(i=0; i<N-1; i++) {
		h[i] = pnt[i+1].x - pnt[i].x;
	}

	for (i=1; i<N-1; i++) {
		b[i] = 2.0 * (h[i] + h[i-1]);
		d[i] = 3.0 * ((pnt[i+1].y - pnt[i  ].y) / h[i  ] 
					- (pnt[i  ].y - pnt[i-1].y) / h[i-1]);
	}

	g[1] = h[1] / b[1];

	for (i=2; i<N-2; i++) {
		g[i] = h[i] / (b[i] - h[i-1] * g[i-1]);
	}

	u[1] = d[1] / b[1];

	for(i=2; i<N-1; i++) {
		u[i] = (d[i]-h[i-1] * u[i-1]) / (b[i] - h[i-1] * g[i-1]);
	}
	
	if(idx > 1) {
		k = idx;
	} else {
		k = 1;
	}

	r[0]   = 0.0;
	r[N-1] = 0.0;
	r[N-2] = u[N-2];
	
	for (i=N-3; i>=k; i--) {
		r[i] = u[i] - g[i] * r[i+1];
	}

	double dx = x - pnt[idx].x;
	double q = (pnt[idx+1].y - pnt[idx].y) / h[idx] - h[idx] * (r[idx+1] + 2.0 * r[idx]) / 3.0;
	double s = (r[idx+1] - r[idx]) / (3.0 * h[idx]);
	
	return pnt[idx].y + dx * (q + dx * (r[idx]  + s * dx));
}


int main(void)
{
    FILE *fp;
    char filename[] = "export.csv"; // 出力するファイルの名前を決める
    fp = fopen(filename,"w");
    
	Point2D points[N] =
			{{-5.0, -4.0},
			 {-4.0, -1.0},
			 { 0.0, 0.0},
			 { 4.0, 2.0},
			 { 5.0, 3.0} }; // ここには好きな数値を入れる
    for(int i=0;i<=600;i++){
        float x = 0.01 * i - 3.0;
        fprintf( fp,"%f , %f\n",x,spline(points, x));
    }
    fclose( fp );

    printf( "Output %s end\n", filename );
	
	return 0;
}
