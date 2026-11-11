s32 resolve_path(u8 *path);
void streamLoadRecord(s32 value, s32 extra);
extern u8 gStreamPath[];

/* Resolves the stream path, then loads the record for the given id. */
void streamOpenPath(s32 recordId, s32 extra)
{
    resolve_path(gStreamPath);
    streamLoadRecord(recordId, extra);
}
