#ifndef SPARROWHAWK_NORMALIZER_CONNECTOR_H_
#define SPARROWHAWK_NORMALIZER_CONNECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

int Normalizer_Setup(const char *configuration_proto, const char *pathname_prefix);
int Normalizer_Normalize(const char *input, char **output);

#ifdef __cplusplus
}
#endif

#endif  // SPARROWHAWK_NORMALIZER_CONNECTOR_H_
