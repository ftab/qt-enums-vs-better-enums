# Qt Q_ENUM / QMetaEnum vs better-enums (featuring Qt Creator bug maybe?)
I was looking for a way to do enum reflection and I happened upon a couple of options
* Qt's Q_ENUM and using QMetaEnum to reflect
* https://github.com/aantron/better-enums

Trying these, they both worked well for what I needed, but Qt Creator does not seem to be too happy with them.
I can't even code complete an enum made by better-enums. It also gives me "expected a declaration" errors, even though it actually compiles, leading me to believe it's tripping Qt Creator up somehow.

Tested with
* Qt Creator 4.2.0 (5.7.1 but it didn't support Q_ENUM_NS)
* Qt Creator 4.3.1 (5.9.1)
* Qt Creator 4.4.0 (5.9.1)

See the [Wiki](https://github.com/ftab/qt-enums-vs-better-enums/wiki) for screenshots
