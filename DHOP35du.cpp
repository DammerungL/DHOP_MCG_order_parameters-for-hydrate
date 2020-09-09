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

    int jishu_i[14250][10];
    int jishu_xin[14250];
    int jishu_xin_F[14250];
    double jishu_x[14250][10];
    double jishu_y[14250][10];
    double jishu_z[14250][10];
    int jishu_0[14250];

int main()
{
    cout << "Hello world!" << endl;
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
        //int ii = 0;
        while (getline(OpenFile,lineStr))
        {
            i++;
           //cout<<i<< ":" <<lineStr<<endl;
            if ( i == 2 ) {
                //
                string bN_0;
                istringstream bs(lineStr);
                bs>>bN_0;
                b_N = atoi(bN_0.c_str());
                cout << b_N <<endl;
            }

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
            if (i == (3+b_N)) {
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
    //
    ofstream OUT_print ;
    ii = ii -1;
    OUT_print.open("cs.txt",ios::trunc) ;
    ofstream OUT_print_F ;
    OUT_print_F.open("F.txt",ios::trunc) ;
//    int jishu_i[3488][10];
//    int jishu_xin[3488];
//    int jishu_xin_F[3488];
//    double jishu_x[3488][10];
//    double jishu_y[3488][10];
//   double jishu_z[3488][10];
//    int jishu_0[3488];
    //
    for ( int ti = 0 ; ti<= ii ; ti ++ ) {
        //
        //cout<<ti<<endl;
        int jishu = 0 ;
        for (int tj = 0; tj<= ii; tj++) {
            //
            double sx,sy,sz;
            sx = 0;
            sy = 0;
            sz = 0;
            if ( ( tj !=ti ) && ( typeXu[tj] == "   OW1" ) && ( typeXu[ti] == "   OW1" ) ) {
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
                //cout<<ti<<endl;
                if ( ((sx*sx)+(sy*sy)+(sz*sz)) <= (0.35*0.35) ) {
                    jishu ++;
                    
                    jishu_i[ti][jishu] = tj;//from 1
                    jishu_x[ti][jishu] = sx;
                    jishu_y[ti][jishu] = sy;
                    jishu_z[ti][jishu] = sz;
                }
                //
            }
        }
        //
 //       cout<<ti<<endl;
        OUT_print<<ti<<" ";
      //  cout<<ti<<endl;
        if ( jishu != 0 ) {
            jishu_0[ti] = jishu;
        }
        //
        OUT_print<<jishu_0[ti]<<" ";
        for ( int ccss = 1 ; ccss <= jishu_0[ti] ; ccss ++ ) {
            //
            OUT_print<<jishu_i[ti][ccss]<<" (x: "<<jishu_x[ti][ccss]<<" , y: "<<jishu_y[ti][ccss]<<" , z: "<<jishu_z[ti][ccss]<<" ) ";
        }
        OUT_print<<"\n";
        //
    }
    cout<<jishu_0[8126]<<" "<<jishu_i[8126][1]<<endl;
    //read_bond
    //
    for ( int ti = 0 ; ti<= ii ; ti ++ ) {
        //
        if ( ( typeXu[ti] == "   OW1" ) && ( jishu_0[ti] >= 2 ) ) {
            //
            for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ ) {
                //
                if ( jishu_0[jishu_i[ti][tj]] >= 2 ) {
                    //
                    double a1 = jishu_x[ti][tj] ;
                    double b1 = jishu_y[ti][tj] ;
                    double c1 = jishu_z[ti][tj] ;
                    for ( int hj = 1 ; hj <= jishu_0[jishu_i[ti][tj]] ; hj ++ ) {
                        //
                        if ( jishu_i[jishu_i[ti][tj]][hj] != ti ) {
                            //
                            double a2 = jishu_x[jishu_i[ti][tj]][hj] ;
                            double b2 = jishu_y[jishu_i[ti][tj]][hj] ;
                            double c2 = jishu_z[jishu_i[ti][tj]][hj] ;
                            double Fx1 = (b1*c2) - (b2*c1) ;
                            double Fy1 = (a2*c1) - (a1*c2) ;
                            double Fz1 = (a1*b2) - (a2*b1) ;
                            for ( int hji = 1 ; hji <= jishu_0[ti] ; hji ++ ) {
                                //
                                if ( jishu_i[ti][hji] != jishu_i[ti][tj] ) {
                                    //
                                    double a3 = jishu_x[ti][hji] ;
                                    double b3 = jishu_y[ti][hji] ;
                                    double c3 = jishu_z[ti][hji] ;
                                    double Fx2 = (b1*c3) - (b3*c1) ;
                                    double Fy2 = (a3*c1) - (a1*c3) ;
                                    double Fz2 = (a1*b3) - (a3*b1) ;
                                    double seta_cos = ( (Fx1*Fx2) + (Fy1*Fy2) + (Fz1*Fz2) ) / ( sqrt ( ( (Fx1*Fx1) + (Fy1*Fy1) + (Fz1*Fz1) )*( (Fx2*Fx2) + (Fy2*Fy2) + (Fz2*Fz2) ) ) ) ;
                                    if ( ( seta_cos>=0.819152 ) && (seta_cos<=1) ) {
                                        //
                                        jishu_xin[ti] ++ ;
                                    }
                                }
                            }
                            //
                        }
                        //ifend
                    }
                    //for3
                }//if2
            }
            //for2
        }
        //print ti shu
        OUT_print<<ti<<" "<<jishu_xin[ti]<<endl;
        if ( (jishu_xin[ti] == 11) || (jishu_xin[ti] == 12) ) {
            //
         //   OUT_print_F<<ti<<" ";
        }
        //OUT_print_F<<ti<<" ";
        //if1
    }
    //for1
    for ( int ti = 0 ; ti<= ii ; ti ++ ) {
        int linsj = 0 ;
        if ( (typeXu[ti] == "   OW1") && ( ( (jishu_xin[ti] == 11) || (jishu_xin[ti] == 12) ) ) ) {
            //
            for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ ) {
                //
                if ( (jishu_xin[jishu_i[ti][tj]] == 11) || (jishu_xin[jishu_i[ti][tj]] == 12) ) {
                    //
                    linsj ++ ;
                }
            }
        }
        if (linsj>=3) {
            //
            //OUT_print_F<<ti<<" ";
            jishu_xin_F[ti] = 1 ;
            for (int tj = 1 ; tj <= jishu_0[ti] ; tj ++) {
                //
                jishu_xin_F[jishu_i[ti][tj]] = 1 ;
            }
        }
    }
    //
    for ( int ti = 0 ; ti<= ii ; ti ++ ) {
        //
        if ( jishu_xin_F[ti] == 1 ) {
            //
            int linshi_2 = 0 ;
            OUT_print_F<<ti<<" ";
            for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ ) {
                //
                if ( jishu_xin_F[jishu_i[ti][tj]] == 1 ) {
                    //
                    linshi_2 ++ ;
                }
            }//for end
            OUT_print_F<<linshi_2<<" ";
            for ( int tj = 1 ; tj <= jishu_0[ti] ; tj ++ ) {
                //
                if ( jishu_xin_F[jishu_i[ti][tj]] == 1 ) {
                    //
                    OUT_print_F<<jishu_i[ti][tj]<<" ";
                }
            }//end if
            OUT_print_F<<endl;
        }
    }
    //final
    system("perl liantong.pl");
    OUT_print.close();
    OUT_print_F.close();
    return 0;
}
