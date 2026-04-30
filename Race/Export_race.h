#ifndef EXPORT_RACE_H
#define EXPORT_RACE_H

#ifdef RACE_LIBRARY_EXPORTS  
#define RACE_API __declspec(dllexport)
#else
#define RACE_API __declspec(dllimport)
#endif

#endif