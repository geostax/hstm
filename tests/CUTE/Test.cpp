
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

// TODO #include the headers for the code you want to test

#include "SpatialIndex.h"
#include "SpatialVector.h"
#include "SpatialInterface.h"

// TODO Add your test functions

void lookupID() {
	int depth          = 4;
	int saveDepth      = 5;
	htmInterface *htm_ = new htmInterface(depth,saveDepth);
	float64 x =  0.50350931157595497;
	float64 y = -0.6109330459045055;
	float64 z = -0.6109330459045055;

	int id_ = htm_ ->lookupID(x,y,z);
    ASSERT_EQUALM("id from lookupID(x,y,z)",id_,3070);

    char name_[1024];
    htm_->index().nameById(id_,name_);
    //cout << "name_: '" << name_ << "'" << endl << flush;
   	ASSERT_EQUALM("checking nameByID",name_,"S33332");
}
void runSuite(int argc, char const *argv[]){
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<>  > lis(xmlfile.out);
	cute::suite s;
	s.push_back(CUTE(lookupID));
	cute::makeRunner(lis,argc,argv)(s, "testTestSuite");
}

int main(int argc, char const *argv[]){
    runSuite(argc,argv);
}

