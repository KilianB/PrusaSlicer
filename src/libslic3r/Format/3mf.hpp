#ifndef slic3r_Format_3mf_hpp_
#define slic3r_Format_3mf_hpp_

namespace Slic3r {

    /* The format for saving the SLA points was changing in the past. This enum holds the latest version that is being currently used.
     * Examples of the Slic3r_PE_sla_support_points.txt for historically used versions:

     *  version 0 : object_id=1|-12.055421 -2.658771 10.000000
                    object_id=2|-14.051745 -3.570338 5.000000
        // no header and x,y,z positions of the points)

     * version 1 :  ThreeMF_support_points_version=1
                    object_id=1|-12.055421 -2.658771 10.000000 0.4 0.0
                    object_id=2|-14.051745 -3.570338 5.000000 0.6 1.0
        // introduced header with version number; x,y,z,head_size,is_new_island)
    */

    enum {
        support_points_format_version = 1
    };

    class Model;
    class DynamicPrintConfig;
#if ENABLE_THUMBNAIL_GENERATOR
    struct ThumbnailData;
#endif // ENABLE_THUMBNAIL_GENERATOR

    // Load the content of a 3mf file into the given model and preset bundle.
    extern bool load_3mf(const char* path, DynamicPrintConfig* config, Model* model, bool check_version);

    // Save the given model and the config data contained in the given Print into a 3mf file.
    // The model could be modified during the export process if meshes are not repaired or have no shared vertices
#if ENABLE_CONFIGURABLE_PATHS_EXPORT_TO_3MF_AND_AMF
#if ENABLE_THUMBNAIL_GENERATOR
    extern bool store_3mf(const char* path, Model* model, const DynamicPrintConfig* config, bool fullpath_sources, const ThumbnailData* thumbnail_data = nullptr);
#else
    extern bool store_3mf(const char* path, Model* model, const DynamicPrintConfig* config, bool fullpath_sources);
#endif // ENABLE_THUMBNAIL_GENERATOR
#else
#if ENABLE_THUMBNAIL_GENERATOR
    extern bool store_3mf(const char* path, Model* model, const DynamicPrintConfig* config, const ThumbnailData* thumbnail_data = nullptr);
#else
    extern bool store_3mf(const char* path, Model* model, const DynamicPrintConfig* config);
#endif // ENABLE_THUMBNAIL_GENERATOR
#endif // ENABLE_CONFIGURABLE_PATHS_EXPORT_TO_3MF_AND_AMF

}; // namespace Slic3r

#endif /* slic3r_Format_3mf_hpp_ */
