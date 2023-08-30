#include <cstdlib>

#include <sparrowhawk/normalizer_connector.h>
#include <sparrowhawk/normalizer.h>

#ifdef __cplusplus
extern "C" {
#endif

using speech::sparrowhawk::Normalizer;
static Normalizer *Normalizer_instance = NULL;

void lazyNormalizer() {
    if (Normalizer_instance == NULL) {
        Normalizer_instance = new Normalizer();
    }
}

int Normalizer_Setup(const char *configuration_proto, const char *pathname_prefix) {
    lazyNormalizer();
    string configuration_proto_string(configuration_proto);
    string pathname_prefix_string(pathname_prefix);
    bool retValue = Normalizer_instance->Setup(configuration_proto_string, pathname_prefix_string);
    return retValue ? 1 : 0;
}

int Normalizer_Normalize(const char *input, char **output) {
    lazyNormalizer();
    string input_string(input);
    string output_string;
    bool retValue = Normalizer_instance->Normalize(input_string, &output_string);
    if (retValue) {
        int length = output_string.length();
        *output = new char[length + 1];
        strcpy(*output, output_string.c_str());
        *output[length] = '\0';
        return length + 1;
    }
    return -1;
}

#ifdef __cplusplus
}
#endif