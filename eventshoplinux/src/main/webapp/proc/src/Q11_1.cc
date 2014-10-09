#include "spatial_analysis.h"
#include "temporal_analysis.h"

#include <ctime>

using namespace cv;

int main()
{
	EmageIngestor ds349("/home/ing/eventshop/temp/ds349");
	int rows0 = 1490;
	int cols0 = 1160;
	Mat mask0(rows0 , cols0 , CV_8U);
	for(int i = 0; i < rows0; ++i)
	{
		for(int j = 0; j < cols0; ++j)
		{
			if(j <= 1160 && j> 0 && i<=1490 && i> 0)
				mask0.at<unsigned char>(i, j) = 255;
			else
				mask0.at<unsigned char>(i, j) = 0;
		}
	}
	FilterCondition fcond0(mask0, LT, -99999, 99999, 1408646556173, 9223372036854775807, true, 0, 100);
	Filter Q11_1(ds349, fcond0);

	while(true)
	{
		while(Q11_1.has_next())
		{
			Emage e = Q11_1.next();
			create_output(e, "/usr/share/tomcat7/webapps/eventshoplinux/temp/queries/Q11_1");
		}
		sleep(100);
	}
	return 0;
}
