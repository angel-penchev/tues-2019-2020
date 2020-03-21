#include "ui.h"
#include <pthread.h>
#include <unistd.h>

#define MINER_THREADS 2000

int gold = 100;
int soldiers = 0;
int miners = 0;
int zombies = 1;
int health = 100;

void *init_miner();
void *init_zombies();
static pthread_mutex_t mutex;

int main() {
	init();
	print_gold(gold);
	print_soldiers(soldiers);
	print_zombies(5, 13);
	print_health(health);

	pthread_t miner_threads[MINER_THREADS];
	pthread_t zombie_thread;

	pthread_mutex_init(&mutex, NULL);	
	pthread_create(&zombie_thread, NULL, init_zombies, NULL);

	while(1) {
		int ch = get_input();
		switch(ch) {
			case 'm':
				pthread_mutex_lock(&mutex);
				if (gold < 100) {
					print_fail("Not enough gold!");
					pthread_mutex_unlock(&mutex);
					break;
				}

				pthread_create(&miner_threads[miners++], NULL, init_miner, NULL);

				gold -= 100;
				print_msg("Miner created!");
				pthread_mutex_unlock(&mutex);
				break;

			case 's':
				pthread_mutex_lock(&mutex);
				if (gold < 10) {
					print_fail("Not enough gold!");
					pthread_mutex_unlock(&mutex);
					break;
				}

				soldiers++;
				gold -= 10;
				print_msg("Soldier created!");
				pthread_mutex_unlock(&mutex);
				break;

			case 'x':
				pthread_mutex_lock(&mutex);
				if (gold < 100) {
					print_fail("Not enough gold!");
					pthread_mutex_unlock(&mutex);
					break;
				}

				soldiers += 10;
				gold -= 100;
				print_msg("10 x soldiers created!");
				pthread_mutex_unlock(&mutex);
				break;

			case 'q':
				pthread_mutex_lock(&mutex);
				game_end(zombies);
				pthread_mutex_unlock(&mutex);
				break;
		}

		pthread_mutex_lock(&mutex);
		print_gold(gold);
		print_soldiers(soldiers);
		print_health(health);

		if (health <= 0) {
			pthread_mutex_lock(&mutex);
			game_end(zombies);
			pthread_mutex_unlock(&mutex);
		}
		pthread_mutex_unlock(&mutex);
	}
}

void *init_miner() {
    //------------------------------------------------------------------------
    // FUNCTION: count_primes
    // Counts the amount of primes between 2 and N-1
    // PARAMETERS:
    // void * parameters - contains N (number)
    //------------------------------------------------------------------------

    for(;;) {
		pthread_mutex_lock(&mutex);
		gold += 10;
		print_gold(gold);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void *init_zombies() {
	for (;; zombies *= 2) {
		for (unsigned int i = 5; i > 0; i--) {
			pthread_mutex_lock(&mutex);
			print_zombies(i, zombies);
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}

		if (zombies > soldiers) {
			pthread_mutex_lock(&mutex);
			health -= zombies - soldiers;
			if (health <= 0) {
				game_end(zombies);
			}
			print_fail("Zombie attack succeded ;(!");
			pthread_mutex_unlock(&mutex);
		} else {
			print_succ("Zombie attack deflected! :)");
		}
	}
}
