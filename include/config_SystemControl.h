



//***SYSTEM OPERATIONAL PARAMETER DEFINITIONS***/
#define GEN_OUTPUT_LIM    100.00 // Output wattage limit of the specified generator.

// The following are operational modes of the PerformanceMonitor,
// with consideration to the generators performance.
#define GEN_OUTPUT_ERROR    0
#define GEN_ACTIVE          1

// System mode variables and definitions:
#define ERROR_GEN_TEMP_TOO_HIGH -1
#define ERROR_GEN_TEMP_TOO_LOW -2
#define ERROR_GEN_ILOW -3
#define ERROR_GEN_IHIGH -4
#define ERROR_GEN_VLOW -5


int sys_mode; // Defines operational mode of PerformanceMonitor.
