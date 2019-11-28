#include <stdio.h>
#include <stdlib.h>
#include "nspv.h"

#include "libbtc-config.h"

#include <btc/chainparams.h>
#include <btc/ecc.h>
#include <btc/net.h>
#include <btc/netspv.h>
#include <btc/protocol.h>
#include <btc/random.h>
#include <btc/serialize.h>
#include <btc/tool.h>
#include <btc/tx.h>
#include <btc/utils.h>
#include <btc/wallet.h>

#include <assert.h>
#include <getopt.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <nSPV_defs.h>

#include "nspv/tweetnacl.c"
#include "nspv/curve25519.c"
#include "nspv/nSPV_utils.h"
#include "nspv/nSPV_structs.h"
#include "nspv/nSPV_CCtx.h"
#include "nspv/nSPV_superlite.h"
#include "nspv/nSPV_wallet.h"
#include "nspv/nSPV_htmlgui.h"
#include "nspv/komodo_cJSON.c"
#include "nspv/nSPV_rpc.h"

int main(void) {

    char *argv[] = {"0", "KMD" };
    // argv[1] = "KMD";
    // argv[2] = "13.00";
    
    startnspv(0, argv);

    return 0;
}