#include <iostream>
#include <iostream>
#include <complex>
#include <math.h>
#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main ()
{
	cout << "Hello World" << endl;
	cout.precision(16);
	ifstream OpenFile("panding.gro", ios::in);
	if (OpenFile.fail())
	{
		cout<<"Can not open target file"<<endl;
		return 0;
	 }
	 std::string lineStr;
	 std::vector<int> Xu ;
	 std::vector<string> typeXu ;
	 std::vector<double> x ;
	 std::vector<double> y ;
	 std::vector<double> z ;
	 double boxx;
	 double boxy;
	 double boxz;
	 int ii = 0;
	 int b_N = 0 ;
	 if (OpenFile)
	 {
		 int i = 0;
		 while (getline(OpenFile,lineStr))
		 {
			 i++;
			 if ( i == 2 ) {
				 string bN_0;
				 istringstream bs(lineStr);
				 bs>>bN_0;
				 b_N = atoi(bN_0.c_str());
				 cout << b_N <<endl;
			 }
			 //
			 if ( (i >= 3) && (i < (3+b_N)) )
			 {
				 ii ++;
				 string a1,a2,a3,a4,a5,a6;
				 //istringstream is(lineStr);
				 //is>>a1>>a2>>a3>>a4>>a5;
				 a1 = lineStr.substr(0,8);
				 a2 = lineStr.substr(9,6);//type
				 a3 = lineStr.substr(15,5);//XU
				 a4 = lineStr.substr(21,8);
				 a5 = lineStr.substr(29,8);
				 a6 = lineStr.substr(37,8);
				 //cout<<a1<<","<<a2<<","<<a3<<","<<a4<<","<<a5<<endl;
				 Xu.push_back(atoi(a3.c_str()));
				 typeXu.push_back(a2.c_str());
				 x.push_back(atof(a4.c_str()));
				 y.push_back(atof(a5.c_str()));
				 z.push_back(atof(a6.c_str()));
			 }
			 if ( i == (3+b_N) )
			 {
				 string box_x,box_y,box_z;
				 istringstream ip(lineStr);
				 ip>>box_x>>box_y>>box_z;
				 boxx = atof(box_x.c_str());
				 boxy = atof(box_y.c_str());
				 boxz = atof(box_z.c_str());
			 }
		 }
	 }
	 OpenFile.close();
	 int t ;
	 t = ii - 1 ;
	 cout<<"####"<<t<<"####"<< Xu[t] << "," << typeXu[t] << "," << x[t] << "," << y[t] << "," << z[t] <<endl ;
	 cout<<boxx<<":"<<endl;
	 cout<<boxy<<":"<<endl;
	 cout<<boxz<<":"<<endl;
	 double const PI = acos(double(-1));
	 cout<<PI<<endl;
	 ofstream OUT_print ;
	 OUT_print.open("cs.txt",ios::trunc) ;
	 ofstream OUT_print_F ;
   OUT_print_F.open("F.txt",ios::trunc) ;
	 ii = ii - 1 ;
	// int C_i = 0;
	 long jishu_i[3303][50];
	 int jishu_xin[3303];
	 int jishu_xin_F[3303];
	 double jishu_x[3303][50];
	 double jishu_y[3303][50];
	 double jishu_z[3303][50];
	 int jishu_0[3303];
	 int jishu_0_MCG[3303];
	 int jishu_w_MCG[3303][50];
	 for ( int ti = 0 ; ti<= ii ; ti ++ ) {
        //
   //     cout<<ti<<endl;
        int jishu = 0 ;
        for (int tj = 0; tj<= ii; tj++) {
            //
            double sx,sy,sz;
            sx = 0;
            sy = 0;
            sz = 0;
            if ( ( tj !=ti ) && ( typeXu[tj] == "   C  " ) && ( typeXu[ti] == "   C  " ) ) {
                if ( (abs(x[ti]-x[tj])) > (boxx/2) ){
                        if (((x[tj])-x[ti])<0) {
                            sx = (boxx) - ((x[ti])-(x[tj]));
                        }else{
                            sx = -((boxx) - ((x[tj])-(x[ti])));
                        }

                }else{
                    sx = (x[tj]-x[ti]);
                }
                //
                if ( (abs(y[ti]-y[tj])) > (boxy/2) ){
                        if (((y[tj])-y[ti])<0) {
                            sy = (boxy) - ((y[ti])-(y[tj]));
                        }else{
                            sy = -((boxy) - ((y[tj])-(y[ti])));
                        }

                }else{
                    sy = (y[tj]-y[ti]);
                }
                //
                if ( (abs(z[ti]-z[tj])) > (boxz/2) ){
                        if (((z[tj])-z[ti])<0) {
                            sz = (boxz) - ((z[ti])-(z[tj]));
                        }else{
                            sz = -((boxz) - ((z[tj])-(z[ti])));
                        }

                }else{
                    sz = (z[tj]-z[ti]);
                }
                //
                if ( ((sx*sx)+(sy*sy)+(sz*sz)) <= (0.90*0.90) ) {
                //		OUT_print<<((sx*sx)+(sy*sy)+(sz*sz))<<endl;
                    jishu ++;
                    jishu_i[ti][jishu] = tj;//from_1
                    jishu_x[ti][jishu] = sx;
                    jishu_y[ti][jishu] = sy;
                    jishu_z[ti][jishu] = sz;
                }
                //
            }
        }
        //
        OUT_print<<ti<<" ";
      //  cout<<ti<<endl;
     //   if ( jishu != 0 ) {
            jishu_0[ti] = jishu;
     //   }
        //
        OUT_print<<jishu_0[ti]<<" ";
        for ( int ccss = 1 ; ccss <= jishu_0[ti] ; ccss ++ ) {
            //
            OUT_print<<"["<<ti<<","<<ccss<<"] "<<jishu_i[ti][ccss]<<" (x: "<<jishu_x[ti][ccss]<<" , y: "<<jishu_y[ti][ccss]<<" , z: "<<jishu_z[ti][ccss]<<" ) ";
        }
        OUT_print<<"\n";
        //
    }
    cout<<jishu_0[6]<<" "<<jishu_i[6][1]<<" x "<<jishu_x[6][1]<<endl;
	 //
	 for ( int ti = 0 ; ti <= ii ; ti ++ )
	 {
		 if ( ( typeXu[ti] == "   C  " ) && ( jishu_0[ti] != 0 ) )
		 {
			 //
			 for ( int w_ti = 1 ; w_ti <= ii ; w_ti ++ ) 
			 {
				 if ( typeXu[w_ti] == "   OW1" )
				 {
					 //
					 double sx1,sy1,sz1;
					 sx1 = 0;
					 sy1 = 0;
					 sz1 = 0;
					 if ( (abs(x[ti]-x[w_ti])) > (boxx/2) )
					 {
						 if (((x[w_ti])-x[ti])<0) 
						 {
							 sx1 = (boxx) - ((x[ti])-(x[w_ti]));
						 }else{
							 sx1 = -((boxx) - ((x[w_ti])-(x[ti])));
						 }
					 }else{
						 sx1 = (x[w_ti]-x[ti]);
					 }
					 //
					 if ( (abs(y[ti]-y[w_ti])) > (boxy/2) )
					 {
						 if (((y[w_ti])-y[ti])<0)
						 {
							 sy1 = (boxy) - ((y[ti])-(y[w_ti]));
						 }else{
							 sy1 = -((boxy) - ((y[w_ti])-(y[ti])));
						 }
					 }else{
						 sy1 = (y[w_ti]-y[ti]);
					 }
					 //
					 if ( (abs(z[ti]-z[w_ti])) > (boxz/2) ) 
					 {
						 if (((z[w_ti])-z[ti])<0)
						 {
							 sz1 = (boxz) - ((z[ti])-(z[w_ti]));
						 }else{
							 sz1 = -((boxz) - ((z[w_ti])-(z[ti])));
						 }
					 }else{
						 sz1 = (z[w_ti]-z[ti]);
					 }
					 //
					 double R1 = 0;
					 R1 = sqrt( (sx1*sx1)+(sy1*sy1)+(sz1*sz1) ) ;
					 if ( R1 <= 0.6 ) 
					 {
						 //R2
						 OUT_print<<"R1: "<<R1<<endl;
						 for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ )
						 {
							 //
							 double sx2,sy2,sz2;
							 sx2 = 0;
							 sy2 = 0;
							 sz2 = 0;
							 int C_index2 = jishu_i[ti][tj];
							 OUT_print<<ti<<" ("<<jishu_0[ti]<<")"<<" "<<jishu_i[ti][tj]<<endl;
							 if ( (abs(x[C_index2]-x[w_ti])) > (boxx/2) )
							 {
								 if (((x[w_ti])-x[C_index2])<0)
								 {
									 sx2 = (boxx) - ((x[C_index2])-(x[w_ti]));
								 }else{
									 sx2 = -((boxx) - ((x[w_ti])-(x[C_index2])));
								 }
							 }else{
								 sx2 = (x[w_ti]-x[C_index2]);
							 }
							 //
							 if ( (abs(y[C_index2]-y[w_ti])) > (boxy/2) )
							 {
								 if (((y[w_ti])-y[C_index2])<0)
								 {
									 sy2 = (boxy) - ((y[C_index2])-(y[w_ti]));
								 }else{
									 sy2 = -((boxy) - ((y[w_ti])-(y[C_index2])));
								 }
							 }else{
								 sy2 = (y[w_ti]-y[C_index2]);
							 }
							 //
							 if ( (abs(z[C_index2]-z[w_ti])) > (boxz/2) )
							 {
								 if (((z[w_ti])-z[C_index2])<0)
								 {
									 sz2 = (boxz) - ((z[C_index2])-(z[w_ti]));
								 }else{
									 sz2 = -((boxz) - ((z[w_ti])-(z[C_index2])));
								 }
							 }else{
								 sz2 = (z[w_ti]-z[C_index2]);
							 }
							 //
							 double R2 = 0;
							 R2 = sqrt( (sx2*sx2)+(sy2*sy2)+(sz2*sz2) ) ;
							 if ( R2 <= 0.6 ) 
							 {
							 	 OUT_print<<"R2: "<<R2<<endl;
							 	 double R0;
								 R0 = sqrt((jishu_x[ti][tj] * jishu_x[ti][tj]) + (jishu_y[ti][tj] * jishu_y[ti][tj]) + (jishu_z[ti][tj] * jishu_z[ti][tj])) ;
								 OUT_print<<"R0: "<<R0<<endl;
								 double cos1, cos2;
								 cos1 = 0;
								 cos2 = 0;
								 cos1 = ((R1*R1)+(R0*R0)-(R2*R2))/(2*R1*R0);
								 cos2 = ((R2*R2)+(R0*R0)-(R1*R1))/(2*R2*R0);
								 OUT_print<<"cos1: "<<cos1<<" cos2:"<<cos2<<endl;
								 if ( (cos1 >= 0.7071) && (cos2 >= 0.7071) )
								 {
									 jishu_w_MCG[ti][tj] ++;
									 //cout<<"Y"<<endl;
								 } 
							 }
							 //
						 }
					 } 
				 }
				 //R1_R2
			 }
			 //
			 int panding = 0 ;
			 for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ )
			 {
			// 		OUT_print<<ti<<" "<<tj<<" "<<jishu_w_MCG[ti][tj]<<endl;
			 		if ( jishu_w_MCG[ti][tj] == 5 )
			 		{
			 				panding ++;
			 		}
			 }
			 if ( panding >=3 ) {
			 		jishu_0_MCG[ti] = 1;
			 		OUT_print_F<<ti<<" "<<jishu_0[ti]<<" ";
			 		for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ ) {
			 			OUT_print_F<<jishu_i[ti][tj]<<" ";
			 		}
			 		OUT_print_F<<endl;
			 }
			 //
		 } 
	 } 
	 //
	 system("perl liantongMCG.pl");
   OUT_print.close();
   OUT_print_F.close();
   return 0;
}
