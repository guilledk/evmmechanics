#include <eosio/eosio.hpp>
#include <math.h>

#pragma precision=log10l(ULLONG_MAX)/2
typedef enum { FALSE=0, TRUE=1 } BOOL;


using namespace eosio;

class [[eosio::contract("evmmechanics")]] evmmechanics : public eosio::contract {
    public:
        using contract::contract;

        /**
         * Simulate an expensive read only evm raw
         */
        [[eosio::action]] void roevm(uint64_t prime_max) {
            // Only let us run this
            require_auth(_self);

            uint64_t p;

            for (p = 2; p <= prime_max; p += 1) {
                if (is_prime(p) && is_mersenne_prime(p)) {
                    eosio::print_f(" %u", p);
                }
            }

            eosio::check(false, "reached assert");
        }


    private:

        BOOL is_prime(int p) {
            if (p == 2) {
                return TRUE;
            } else if (p <= 1 || p % 2 == 0) {
                return FALSE;
            }

            BOOL prime = TRUE;
            const int to = sqrt(p);
            int i;
            for (i = 3; i <= to; i += 2) {  
                if (!((prime = BOOL(p)) % i)) break;
            }
            return prime;
        }

        BOOL is_mersenne_prime(int p) {
            if (p == 2) return TRUE;

            const long long unsigned m_p = (1LLU << p) - 1;
            long long unsigned s = 4;
            int i;
            for (i = 3; i <= p; i++) {
                s = (s * s - 2) % m_p;
            }
            return BOOL(s == 0);
        }

};
