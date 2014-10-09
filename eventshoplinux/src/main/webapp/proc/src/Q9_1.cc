#include "spatial_analysis.h"
#include "temporal_analysis.h"

#include <ctime>

using namespace cv;

int main()
{
	EmageIngestor ds346("/home/ing/eventshop/temp/ds346");
	vector<GroupingColors> grpColors;
	grpColors.push_back(green);
	grpColors.push_back(yellow);
	grpColors.push_back(red);

	GroupingCriteria gcrit0 = GroupingCriteria();
	gcrit0.critGrpType = gt_absolute;
	vector<double> thresh0;
	thresh0.push_back(30);
	thresh0.push_back(70);
	gcrit0.setThresholds(thresh0);
	Grouping Q9_1(ds346, gcrit0, false, true, grpColors);
	while(true)
	{
		while(Q9_1.has_next())
		{
			Emage e = Q9_1.next();
			create_output(e, "/usr/share/tomcat7/webapps/eventshoplinux/temp/queries/Q9_1");
		}
		sleep(100);
	}
	return 0;
}
