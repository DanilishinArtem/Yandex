
#include <map>
#include <set>
#include <string>
#include "synonims.h"
#include "testFramework.h"


void TestAddSynonims(){
    {
        Synonims empty;
        AddSynonims(empty, "a", "b");
        const Synonims expected = {
            {"a", {"b"}},
            {"b", {"a"}},
        };
        AssertEqual(empty, expected, "AssertEqual");
    }
    {
        Synonims synonims = {
            {"a" , {"b"}},
            {"b" , {"a", "c"}},
            {"c" , {"b"}},
        };
        AddSynonims(synonims, "a", "c");
        const Synonims expected = {
            {"a" , {"b", "c"}},
            {"b" , {"a", "c"}},
            {"c" , {"b", "a"}},
        };
        AssertEqual(synonims, expected, "AssertEqual");
    }
}

void TestSynonimsCount(){
    {
        Synonims empty;
        AssertEqual(GetSynonimCount(empty, "a"), 0, "count for a (str: 62)");
    }
    {
        Synonims synonims = {
            {"a" , {"b", "c"}},
            {"b" , {"a"}},
            {"c" , {"a"}},
        };
        AssertEqual(GetSynonimCount(synonims, "a"), 2, "count for a (str: 70)");
        AssertEqual(GetSynonimCount(synonims, "b"), 1, "count for b (str: 71)");
        AssertEqual(GetSynonimCount(synonims, "z"), 0, "count for z (str: 72)");
    }
}

void TestCheckSynonim(){
    {
        Synonims empty;
        AssertEqual(CheckSynonim(empty, "a", "b"), false, "AssertEqual");
    }
    {
        Synonims synonims = {
            {"a" , {"b", "c"}},
            {"b" , {"a"}},
            {"c" , {"a"}},
        };
        AssertEqual(CheckSynonim(synonims, "a", "b"), true, "CheckSynonim");
        AssertEqual(CheckSynonim(synonims, "b", "a"), true, "CheckSynonim");
        AssertEqual(CheckSynonim(synonims, "a", "c"), true, "CheckSynonim");
        AssertEqual(CheckSynonim(synonims, "c", "a"), true, "CheckSynonim");
        AssertEqual(CheckSynonim(synonims, "b", "c"), false, "CheckSynonim");
    }
}

void TestProgramm(){
    TestRunner tr;
    tr.RunTest(TestAddSynonims, "TestAddSynonims");
    tr.RunTest(TestSynonimsCount, "TestAddSynonims");
    tr.RunTest(TestCheckSynonim, "TestAddSynonims");
}