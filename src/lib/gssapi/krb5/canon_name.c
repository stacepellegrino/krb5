/*
 * lib/gssapi/krb5/canon_name.c
 *
 * Copyright 1997 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 *
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 *
 */

#include "gssapiP_krb5.h"

/* This is trivial since we're a single mechanism implementation */

OM_uint32 gss_canonicalize_name(OM_uint32  *minor_status,
				const gss_name_t input_name,
				const gss_OID mech_type,
				gss_name_t *output_name)
{
	if ((mech_type == GSS_C_NULL_OID) ||
	    !g_OID_equal(mech_type, gss_mech_krb5)) {
		if (minor_status)
			*minor_status = 0;
		return(GSS_S_BAD_MECH);
	}
		
	return gss_duplicate_name(minor_status, input_name,
				  output_name);
}
