#include "spatial_analysis.h"
#include "temporal_analysis.h"

#include <ctime>

using namespace cv;

int main()
{
	EmageIngestor ds346("/home/ing/eventshop/temp/ds346");
	EmageIngestor ds347("/home/ing/eventshop/temp/ds347");

	vector<ProcEmageIterator*> eits0;
	eits0.push_back(&ds346);
	eits0.push_back(&ds347);

	Aggregate Q10_1(eits0, AggSUM);

	while(true)
	{
		while(Q10_1.has_next())
		{
			Emage e = Q10_1.next();
			create_output(e, "/usr/share/tomcat7/webapps/eventshoplinux/temp/queries/Q10_1");
		}
		sleep(100);
	}
	return 0;
}
