#ifndef CSM_TOOLS_PATHGRIDCHECK_H
#define CSM_TOOLS_PATHGRIDCHECK_H

#include <algorithm>
#include <vector>

#include "../doc/stage.hpp"

namespace CSMDoc
{
    class Messages;
}

namespace CSMWorld
{
    struct Pathgrid;
    template <typename T, typename AT>
    class SubCellCollection;
    template <typename ESXRecordT>
    struct IdAccessor;
}

namespace CSMTools
{
    struct Point
    {
        unsigned char mConnectionNum;
        std::vector<int> mOtherIndex;
        Point()
            : mConnectionNum(0)
            , mOtherIndex(0)
        {
        }
    };

    class PathgridCheckStage : public CSMDoc::Stage
    {
        const CSMWorld::SubCellCollection<CSMWorld::Pathgrid, CSMWorld::IdAccessor<CSMWorld::Pathgrid>>& mPathgrids;
        bool mIgnoreBaseRecords;

    public:
        PathgridCheckStage(
            const CSMWorld::SubCellCollection<CSMWorld::Pathgrid, CSMWorld::IdAccessor<CSMWorld::Pathgrid>>& pathgrids);

        int setup() override;

        void perform(int stage, CSMDoc::Messages& messages) override;
    };
}

#endif // CSM_TOOLS_PATHGRIDCHECK_H
