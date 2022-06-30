project from the 42 curriculum where we make our own (simplified) version of printf in C.
Following below I've documented some of my process making this project. :)


_Heyyyyyy_

So i thought i’d write down part of my process, It’ll probably still be in my head mostly by the time i eval but i think this is a good practive and it might also be worthwhile testing out with evals in general, I think some notes on your process and struggles in a project can really help the codam learning experience! :)


Okay so printf! Probably took me way longer than I needed, but partially still just learning how everything works (plus personal stuff) And then once i got it figured out i overengineered it super hard and made it way harder than it had to be… So I decided to start over and then i was able to finish it relatively quickly :). (shoutout to ruben for having a very readable printf that helped me realize how i was making mine a bit needlessly complicated).


So first things first let’s start of with..

Variadic arguments
Not to bad looking abc tbh ^^ They were a little confusing at first but i pulled up the exercises from the spark session which helped :)

Though the only tripup i had there was that all the examples (also those found online)
Use the first argument as a counter for the amount of varadic arguments.. Which kinda goes against the whole thing of having them be.. A variable amount xd. So it was making it harder to grasp the concept because ofcourse you can’t tell printf how many arguments/flags it will have.

Luckily i didn’t have to think about this too much however since i can just write out (or buffer store) the string as i read over it, and call va_arg anytime we see a flag :)

Ps: (oh also i had to realise you need to use the exact same va_list every time so if you go between functions make sure to use a pointer towards your list instead of copying the value! ;)


Flag checking approach
Second up is to decide how to see which flag is being used whenever we find a % And how to send it to the right function (or write function haHA). I’ve found mainly 3 approaches.

1 The simple if else tree, easy and simple but it maybe looks a little clanky. I wanted to learn different ways to do it so i didn’t chose this.. But in the end i kinda wish i did… Since the other options all require the printer functions to take exactly the same arguments.


2 Function pointer array

3 lookup table (what i have rn but i don’t think it’s worth since for undefined behavior you need to index through all the valid flags anyways, so it’s not even more efficient…)
Buffer management
So another thing i did in my printf was making a buffer for it. Since write is a ‘system call’ function it’s a little slow every time you use it, so using it for every character and flag would make your printf slower overall. I thought this mattered more than it actually did. Also since once we get to the point where it would actually matter we’re already allowed to use the original printf anyway…

I also had some trouble deciding wether my buffer function should take a character or string. One would require me to use while loops for every multi character flags, while the other one required me to put everything into a string first, and also i didn’t know how to deal with the possibility of getting a string that would be bigger than my buffer. So in the end i scrapped it.


Return value
I forgot about this at first.. But you need to return the amount of bytes written. In my first version i made every flag print function take a int pointer to update the amount of bytes written. But in the second version i just put it in the return value (which made it easier especially since write itself already returns the amount of bytes written)
