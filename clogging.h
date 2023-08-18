#ifndef CLOGGING_H
#define CLOGGING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CLOGGING_RESET "\033[0m"

#define CLOGGING_RED "\033[31m"
#define CLOGGING_GREEN "\033[32m"
#define CLOGGING_YELLOW "\033[33m"
#define CLOGGING_BLUE "\033[34m"

#define CLOGGING_BOLD "\033[1m"
#define CLOGGING_UNDERLINED "\033[4m"


static struct 
{
    bool handle;
    bool paniced;
} CLogging;

#define PANIC(...) \
{ \
    CLogging.paniced = true; \
    if (!CLogging.handle) \
    { \
        fprintf(stderr, "[" CLOGGING_RED "PANIC" CLOGGING_RESET "] %s: ", __FUNCTION__); \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\n"); \
        exit(1); \
    } \
}

#define HANDLE_PANIC(expr) \
{ \
    CLogging.paniced = false; \
    CLogging.handle = true; \
    expr \
    CLogging.handle = false; \
}

#define IS_PANICED (CLogging.paniced)


#define LOG_INFO(...) \
{ \
    fprintf(stderr, "[" CLOGGING_GREEN "INFO" CLOGGING_RESET "] %s: ", __FUNCTION__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n"); \
}

#define LOG_WARN(...) \
{ \
    fprintf(stderr, "[" CLOGGING_YELLOW "WARN" CLOGGING_RESET "] %s: ", __FUNCTION__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n"); \
}

#ifdef DEBUG_LOGGING
    #define LOG_DBG(...) \
    { \
        fprintf(stderr, "[" CLOGGING_BLUE "DEBUG" CLOGGING_RESET "] %s: ", __FUNCTION__); \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    }
#else
    #define LOG_DBG(...)
#endif

#endif // CUTE_VM_LOGGING_H
