#ifndef FILTERS_H
#define FILTERS_H

#include "main.h"

/*
Filtros
***/
const cv::Mat krnGauss=(cv::Mat_<float>(7,7)<<0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387,
                                0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140,
                                0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440,
                                0.008351391561455500, 0.02990238918704820, 0.06427974061178290, 0.08295900303167780, 0.06427974061178290, 0.02990238918704820, 0.008351391561455500,
                                0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440,
                                0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140,
                                0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387);

const cv::Mat krnGabbor_0=(cv::Mat_<float>(7,7)<< 0.219942090078691,   0.311000213036744,	 0.382853031059958,	 0.410319878554183,	 0.382853031059958,	 0.311000213036744,	 0.219942090078691,
                                   -0.360778177422810,	-0.510143783744886,	-0.628006302555330,	-0.673061067539018,	-0.628006302555330,	-0.510143783744886,	-0.360778177422810,
                                   -0.485511373161494,	-0.686517712143974,	-0.845129282723722,	-0.905761001002688,	-0.845129282723722,	-0.686517712143974,	-0.485511373161494,
                                    0.536025919225963,   0.757945762054219,	 0.933059915130099,	                 1,	 0.933059915130099,	 0.757945762054219,	 0.536025919225963,
                                    0.485511373161494,   0.686517712143974,	 0.845129282723722,	 0.905761001002688,	 0.845129282723722,	 0.686517712143974,	 0.485511373161494,
                                   -0.360778177422810,	-0.510143783744886,	-0.628006302555329,	-0.673061067539017,	-0.628006302555329,	-0.510143783744886,	-0.360778177422810,
                                   -0.219942090078691,	-0.311000213036744,	-0.382853031059959,	-0.410319878554183,	-0.382853031059959,	-0.311000213036744,	-0.219942090078691);

const cv::Mat krnGabbor_45=(cv::Mat_<float>(7,7)<< 0.0936538505193276, 0.395788446212621,	 0.275146412309302,	-0.371656367890720,	-0.660485759126544,	-0.180932827883211,	 0.287323786082038,
                                     0.395788446212621,	 0.316041991529005,	-0.490346917282630,	-1.000935896555920,	-0.314949637645769,	 0.574481778215950,	 0.536404028842199,
                                     0.275146412309302,	-0.490346917282630,	-1.14970706499635,	-0.415530574103585,	 0.870600805222588,	 0.933718090255184,	 0.089545106627328,
                                    -0.371656367890720,	-1.00093589655592,	-0.415530574103585,	                 1,	 1.23190620886194,	 0.135701505060078,	-0.549322969084363,
                                    -0.660485759126543,	-0.314949637645768,	 0.870600805222588,	 1.231906208861940,	 0.155871099872671,	-0.724752345861218,	-0.485164321321409,
                                    -0.180932827883210,	 0.574481778215950,	 0.933718090255184,	 0.135701505060078,	-0.724752345861218,	-0.557275295877272,	 0.022114507829037,
                                     0.287323786082039,	 0.536404028842199,	 0.089545106627328, -0.549322969084363,	-0.485164321321409,	 0.022114507829037,	 0.218908093942334);

const cv::Mat krnGabbor_90=(cv::Mat_<float>(7,7)<< 0.219942090078691,	-0.360778177422810,	-0.485511373161494,	0.536025919225963,	0.485511373161494,	-0.360778177422810,	-0.219942090078691,
                            0.311000213036744,	-0.510143783744887,	-0.686517712143974,	0.757945762054219,	0.686517712143974,	-0.510143783744886,	-0.311000213036744,
                            0.382853031059958,	-0.628006302555330,	-0.845129282723722,	0.933059915130099,	0.845129282723722,	-0.628006302555329,	-0.382853031059958,
                            0.410319878554183,	-0.673061067539018,	-0.905761001002688,	                1,	0.905761001002688,	-0.673061067539017,	-0.410319878554183,
                            0.382853031059958,	-0.628006302555330,	-0.845129282723722,	0.933059915130099,	0.845129282723722,	-0.628006302555329,	-0.382853031059959,
                            0.311000213036744,	-0.510143783744887,	-0.686517712143974,	0.757945762054219,	0.686517712143974,	-0.510143783744886,	-0.311000213036745,
                            0.219942090078691,	-0.360778177422810,	-0.485511373161494,	0.536025919225963,	0.485511373161494,	-0.360778177422810,	-0.219942090078691);

const cv::Mat krnGabbor_135=(cv::Mat_<float>(7,7)<< 0.287323786082038,	 0.536404028842199,	 0.0895451066273280, -0.549322969084363,	-0.485164321321409,	 0.0221145078290367,	0.218908093942334,
                             -0.180932827883211,	 0.574481778215950,	 0.933718090255184,   0.135701505060078,	-0.724752345861218,	-0.557275295877272,	    0.0221145078290367,
                             -0.660485759126544,    -0.314949637645769,	 0.870600805222588,   1.23190620886194 ,	 0.155871099872671,	-0.724752345861218,	   -0.485164321321409,
                             -0.371656367890720,	-1.00093589655592,	-0.415530574103585,                   1,	 1.23190620886194,	 0.135701505060078,	   -0.549322969084363,
                              0.275146412309302,	-0.490346917282630,	-1.14970706499635,	 -0.415530574103585,	 0.870600805222588,	 0.933718090255184,	    0.0895451066273277,
                              0.395788446212621,	 0.316041991529005,	-0.490346917282630,	 -1.00093589655592 ,	-0.314949637645768,	 0.574481778215950,	    0.536404028842199,
                              0.0936538505193276,	 0.395788446212621,	 0.275146412309302,	 -0.371656367890720,	-0.660485759126543,	-0.180932827883210,	    0.287323786082039);

const cv::Mat krn7GM=(cv::Mat_<float>(7,7)<< -0.528545425483352, -1.16321150911680, -1.76404041292601, -1.83665351641902, -1.30565703182534, -0.628262666230595, -0.201587652961317,
                      -0.997538512351542, -2.12015899125046, -3.07152968942405, -3.00355592329616, -1.94847777706278, -0.809521433879312, -0.196485966895711,
                      -1.19710939760065, -2.37671196857262, -3.11145023154320, -2.57291311198393, -1.18880212711942, -0.132921943717324, 0.174277500958084,
                      -0.820280826840353, -1.34210032627979, -1.15001285788954, 0, 1.15001285788954, 1.34210032627979, 0.820280826840353,
                      -0.174277500958084, 0.132921943717324, 1.18880212711942, 2.57291311198393, 3.11145023154320, 2.37671196857262, 1.19710939760065,
                      0.196485966895711, 0.809521433879312, 1.94847777706278, 3.00355592329616, 3.07152968942405, 2.12015899125046, 0.997538512351542,
                      0.201587652961317, 0.628262666230595, 1.30565703182534, 1.83665351641902, 1.76404041292601, 1.16321150911680, 0.528545425483352);

const cv::Mat krn7Gb=(cv::Mat_<float>(7,7)<<-0.184970999367485, -0.194056665052631, -0.0884278158808839, -0.0115120408280212, -0.0884278158808839, -0.194056665052631, -0.184970999367485,
                      -0.194056665052631, 0.0977153075956823, 0.731260888986979, 1.09804297485538, 0.731260888986979, 0.0977153075956823, -0.194056665052631,
                      -0.0884278158808839, 0.731260888986979, 2.21136108368106, 3.03055077387349, 2.21136108368106, 0.731260888986979, -0.0884278158808839,
                      -0.0115120408280212, 1.09804297485538, 3.03055077387349, 4.08939784333342, 3.03055077387349, 1.09804297485538, -0.0115120408280212,
                      -0.0884278158808839, 0.731260888986979, 2.21136108368106, 3.03055077387349, 2.21136108368106, 0.731260888986979, -0.0884278158808839,
                      -0.194056665052631, 0.0977153075956823, 0.731260888986979, 1.09804297485538, 0.731260888986979, 0.0977153075956823, -0.194056665052631,
                      -0.184970999367485, -0.194056665052631, -0.0884278158808839, -0.0115120408280212, -0.0884278158808839, -0.194056665052631, -0.184970999367485);

const float RM[6] = {0.0139202540637877, 0.381548664072273, 0.441699197344890, 0.139966961878670, 0.0218076316111491, 0.00216857792142420};
const float Rb[6] = {0.0235043555385241, 0.101177579981801, -0.0414768918749304, -0.0604407877207179, -0.0202598969245134, -0.00369883949678623};

//Mat convolutionK7(Mat image, const float kernel[7][7]);
//float **convolutionK7(float **image,float kernel[7][7],size_t rows, size_t cols);

#endif // FILTERS_H
