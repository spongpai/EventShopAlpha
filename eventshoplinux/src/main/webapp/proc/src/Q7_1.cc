#include "spatial_analysis.h"
#include "temporal_analysis.h"

#include <ctime>

using namespace cv;

int main()
{
	EmageIngestor ds346("/home/ing/eventshop/temp/ds346");
	int rows0 = 75;
	int cols0 = 58;
	Mat mask0(rows0 , cols0 , CV_8U);
	for(int i = 0; i < rows0; ++i)
	{
		for(int j = 0; j < cols0; ++j)
		{
			if(j <= 58 && j> 0 && i<=75 && i> 0)
				mask0.at<unsigned char>(i, j) = 255;
			else
				mask0.at<unsigned char>(i, j) = 0;
		}
	}
	FilterCondition fcond0(mask0, LT, -99999, 99999, 1408309806634, 9223372036854775807, true, 0, 100);
	Filter Q7_1(ds346, fcond0);

	while(true)
	{
		while(Q7_1.has_next())
		{
			Emage e = Q7_1.next();
			create_output(e, "/usr/share/tomcat7/webapps/eventshoplinux/temp/queries/Q7_1_filter");
		}
		sleep(100);
	}
	return 0;
}
