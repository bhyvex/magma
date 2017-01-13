
/**
 * @file /magma/src/providers/prime/messages/chunks/chunks.h
 *
 * @brief DESCRIPTIONxxxGOESxxxHERE
 *
 * $Author$
 * $Date$
 * $Revision$
 *
 */

#ifndef PRIME_CHUNKS_H
#define PRIME_CHUNKS_H

/// signature.c
prime_signature_chunk_t *  signature_chunk_alloc(void);
void                       signature_chunk_cleanup(prime_signature_chunk_t *chunk);
void                       signature_chunk_free(prime_signature_chunk_t *chunk);

/// ephemeral.c
prime_ephemeral_chunk_t *  ephemeral_chunk_alloc(void);
void                       ephemeral_chunk_cleanup(prime_ephemeral_chunk_t *chunk);
void                       ephemeral_chunk_free(prime_ephemeral_chunk_t *chunk);
prime_ephemeral_chunk_t *  ephemeral_chunk_get(secp256k1_key_t *encryption, ed25519_key_t *signing);

/// encrypted.c
prime_encrypted_chunk_t *  encrypted_chunk_alloc(void);
void                       encrypted_chunk_cleanup(prime_encrypted_chunk_t *chunk);
void                       encrypted_chunk_free(prime_encrypted_chunk_t *chunk);

/// chunks.c
stringer_t *  chunk_header_write(prime_message_chunks_t type, size_t size, stringer_t *output);

#endif
