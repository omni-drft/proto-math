#ifndef PMCONSTANTS_H
#define PMCONSTANTS_H

/* Define a macro indicating whether we're building a shared library */
#ifdef SHARED_LIB
    #ifdef WIN32
        #define EXPORT_SYMBOL __declspec(dllexport)
    #else
        #define EXPORT_SYMBOL __attribute__((visibility("default")))
    #endif
#else
    #define EXPORT_SYMBOL
#endif


#define PM_PI		3.1415926535897932384626433
#define PM_EULER	0.5772156649015328606065120

enum pmVectorEnum {
	pmCompact,
	pmFull,
	pmDegrees,
	pmRadians
};

#endif /* PMCONSTANTS_H! */
