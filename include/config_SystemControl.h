



//***SYSTEM OPERATIONAL PARAMETER DEFINITIONS***/
#define GEN_OUTPUT_LIM    100.00 // Output wattage limit of the specified generator.

// The following are operational modes of the PerformanceMonitor,
// with consideration to the generators performance.
#define GEN_OUTPUT_ERROR    0
#define GEN_ACTIVE          1

int sys_mode; // Defines operational mode of PerformanceMonitor.
