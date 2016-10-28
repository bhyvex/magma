
/**
 * @file /magma/src/providers/prime/prime.h
 *
 * @brief DESCRIPTIONxxxGOESxxxHERE
 *
 * $Author$
 * $Date$
 * $Revision$
 *
 */

#ifndef MAGMA_PROVIDERS_PRIME_H
#define MAGMA_PROVIDERS_PRIME_H

#define SECP256K1_KEY_PUB_LEN 33
#define SECP256K1_KEY_PRIV_LEN 32
#define SECP256K1_SHARED_SECRET_LEN 32

#define ED25519_KEY_PUB_LEN 32
#define ED25519_KEY_PRIV_LEN 32
#define ED25519_SIGNATURE_LEN 64

// This allows code to include the PRIME header without first including the OpenSSL headers.
#ifdef HEADER_EC_H
typedef EC_KEY secp256k1_key_t;
#else
typedef void secp256k1_key_t;
#endif

// This allows code to include the PRIME header without first including the OpenSSL headers.
#ifdef ED25519_H
typedef struct {
	ed25519_public_key pub;
	ed25519_public_key priv;
} ed25519_key_t;
#else
typedef void ed25519_key_t;
#endif

typedef enum {
	PRIME_SSR = 1215,                    /**< File contains an ssr*/
    PRIME_SIGNET_ORG = 1776,             /**< File contains an organizational signet */
    PRIME_SIGNET_USER = 1789,            /**< File contains a user signet */
	PRIME_KEY_ORG_ENCRYPTED = 1947,     /**< File contains an encrypted organizational key. */
    PRIME_KEY_ORG = 1952,               /**< File contains organizational keys*/
    PRIME_KEY_USER_ENCRYPTED = 1976,    /**< File contains an encrypted user key. */
	PRIME_KEY_USER = 2013,              /**< File contains user keys*/
    PRIME_MESSAGE_ENCRYPTED = 1847
} prime_type_t;

typedef struct {
	ed25519_key_t *signing;
	secp256k1_key_t *encryption;
} prime_user_key_t;

typedef struct {
	ed25519_key_t *signing;
	secp256k1_key_t *encryption;
} prime_org_key_t;

typedef struct {
	prime_type_t type;
	union {
		prime_org_key_t *org;
		prime_user_key_t *user;
	};
} prime_key_t;

/// prime.c
bool_t   prime_start(void);
void     prime_stop(void);

/// secp256k1.c
secp256k1_key_t *  secp256k1_alloc(void);
stringer_t *       secp256k1_compute_kek(secp256k1_key_t *private, secp256k1_key_t *public, stringer_t *output);
void               secp256k1_free(secp256k1_key_t *key);
secp256k1_key_t *  secp256k1_generate(void);
stringer_t *       secp256k1_private_get(secp256k1_key_t *key, stringer_t *output);
secp256k1_key_t *  secp256k1_private_set(stringer_t *key);
stringer_t *       secp256k1_public_get(secp256k1_key_t *key, stringer_t *output);
secp256k1_key_t *  secp256k1_public_set(stringer_t *key);

#endif

