#ifndef EXPORT_H
#define EXPORT_H

#ifdef TRANSPORT_LIBRARY_EXPORTS  
#define TRANSPORT_API __declspec(dllexport)
#else
#define TRANSPORT_API __declspec(dllimport)
#endif

#endif