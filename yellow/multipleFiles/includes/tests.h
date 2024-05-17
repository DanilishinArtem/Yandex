
#include <map>
#include <set>
#include <string>
#include "synonims.h"
#include "testFramework.h"

void TestAddSynonims();

void TestSynonimsCount();

void TestCheckSynonim();

// void TestProgramm();
void TestProgramm(){
    TestRunner tr;
    tr.RunTest(TestAddSynonims, "TestAddSynonims");
    tr.RunTest(TestSynonimsCount, "TestSynonimsCount");
    tr.RunTest(TestCheckSynonim, "TestCheckSynonim");
}