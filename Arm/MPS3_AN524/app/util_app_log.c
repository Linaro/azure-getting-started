/*
 * Copyright (c) 2019,2020 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdbool.h>

#include "psa/crypto.h"
#include "util_app_log.h"

psa_status_t al_psa_status(psa_status_t status, const char *func_name)
{
	switch (status) {
	case PSA_SUCCESS:
		break;

	/* Generic PSA errors (psa/error.h). */
	case PSA_ERROR_PROGRAMMER_ERROR:
		printf("Programmer error\n");
		break;
	case PSA_ERROR_CONNECTION_REFUSED:
		printf("Connection refused\n");
		break;
	case PSA_ERROR_CONNECTION_BUSY:
		printf("Connection busy\n");
		break;
	case PSA_ERROR_GENERIC_ERROR:
		printf("Generic error\n");
		break;
	case PSA_ERROR_NOT_PERMITTED:
		printf("Not permitted\n");
		break;
	case PSA_ERROR_NOT_SUPPORTED:
		printf("Unsupported operation\n");
		break;
	case PSA_ERROR_INVALID_ARGUMENT:
		printf("Invalid argument\n");
		break;
	case PSA_ERROR_INVALID_HANDLE:
		printf("Invalid handle\n");
		break;
	case PSA_ERROR_BAD_STATE:
		printf("Bad state\n");
		break;
	case PSA_ERROR_BUFFER_TOO_SMALL:
		printf("Buffer too small\n");
		break;
	case PSA_ERROR_ALREADY_EXISTS:
		printf("Already exists\n");
		break;
	case PSA_ERROR_DOES_NOT_EXIST:
		printf("Does not exist\n");
		break;
	case PSA_ERROR_INSUFFICIENT_MEMORY:
		printf("Insufficient memory\n");
		break;
	case PSA_ERROR_INSUFFICIENT_STORAGE:
		printf("Insufficient storage\n");
		break;
	case PSA_ERROR_INSUFFICIENT_DATA:
		printf("Insufficient memory data\n");
		break;
	case PSA_ERROR_SERVICE_FAILURE:
		printf("Service failure\n");
		break;
	case PSA_ERROR_COMMUNICATION_FAILURE:
		printf("Communication failure\n");
		break;
	case PSA_ERROR_STORAGE_FAILURE:
		printf("Storage failure\n");
		break;
	case PSA_ERROR_HARDWARE_FAILURE:
		printf("Hardware failure\n");
		break;
	case PSA_ERROR_INVALID_SIGNATURE:
		printf("Invalid signature\n");
		break;

	/* PSA crypto errors (psa/crypto_values.h). */
	case PSA_ERROR_INSUFFICIENT_ENTROPY:
		printf("CRYPTO: Insufficient entropy\n");
		break;
	case PSA_ERROR_TAMPERING_DETECTED:
		printf("CRYPTO: Tampering detected\n");
		break;

	/* Catch-all error handler. */
	default:
		printf("Unhandled status response: %ld", status);
		break;
	}

	/* Display the calling function name for debug purposes. */
	if (status != PSA_SUCCESS) {
		printf("Function: '%s'", func_name);
	}

	return status;
}
